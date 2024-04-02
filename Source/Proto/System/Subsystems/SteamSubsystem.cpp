// Fill out your copyright notice in the Description page of Project Settings.

#include "SteamSubsystem.h"
#include "../../UI/Menu/LobbyPlayerList.h"
#include "../../UI/UIManager.h"

void USteamSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("Steam Subsystem Initialize Started"));

	if (!SteamAPI_Init())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to initialize Steam Subsystem"));
		return;
	}

	bSteamReady = true;
	UE_LOG(LogTemp, Log, TEXT("Steam Subsystem Initialized"));
}

void USteamSubsystem::Deinitialize()
{
	UE_LOG(LogTemp, Warning, TEXT("Steam Subsystem Deinitialize Started"));
	SteamAPI_Shutdown();
	Super::Deinitialize();
}

bool USteamSubsystem::IsSteamReady()
{
	return bSteamReady;
}

void USteamSubsystem::AttemptCreateLobby()
{
	if (!bSteamReady)
	{
		UE_LOG(LogTemp, Error, TEXT("Attempted to create a Steam lobby when Steam Subsystem was not properly initialized"));
		return;
	}

	SteamAPICall_t hSteamAPICall = SteamMatchmaking()->CreateLobby(k_ELobbyTypeFriendsOnly, 4); // TODO: Remove hardcoded lobby size
	m_OnLobbyCreatedResult.Set(hSteamAPICall, this, &USteamSubsystem::OnLobbyCreated);
}

void USteamSubsystem::OnLobbyCreated(LobbyCreated_t* pResult, bool bIOFailure)
{
	UE_LOG(LogTemp, Log, TEXT("OnLobbyCreated called"));

	if (pResult->m_eResult != k_EResultOK)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create lobby: Bad result from Steam"));
		return;
	}

	if (bIOFailure)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create lobby: IO Failure"));
		return;
	}

	CSteamID LobbyID = pResult->m_ulSteamIDLobby;
	CSteamID LeaderID = SteamUser()->GetSteamID();
	const char* LeaderPersonaName = SteamFriends()->GetPersonaName();
	SteamMatchmaking()->SetLobbyData(LobbyID, "name", LeaderPersonaName);

	// init lobby and populate object
	LobbyInstance = NewObject<ULobby>(this, ULobby::StaticClass());
	LobbyInstance->Initialize(LobbyID, LeaderID);
	UE_LOG(LogTemp, Log, TEXT("Lobby Instance initialized"));
	
	// render player list UI element
	UUIManager::Get()->PromptLobbyPlayerList();
}