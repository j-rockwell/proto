// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "../../Lobby/Lobby.h"
#include "ThirdParty/Steamworks/Steamv153/sdk/public/steam/steam_api.h"
#include "ThirdParty/Steamworks/Steamv153/sdk/public/steam/isteammatchmaking.h"
#include "SteamSubsystem.generated.h"

/**
 *
 */
UCLASS()
class PROTO_API USteamSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	ULobby* GetLobby() { return LobbyInstance; }

	/**
	* Returns true if Steam was properly
	* initialized and SteamAPI calls can be
	* performed.
	*/
	bool IsSteamReady();

	/**
	* AttemptCreateLobby sends a SteamAPI call to
	* attempt a new lobby creation and returns the
	* result in a CCallResult callback m_OnLobbyCreatedResult
	*/
	UFUNCTION(BlueprintCallable, Category="Multiplayer|Steam")
	void AttemptCreateLobby();

private:
	ULobby* LobbyInstance = nullptr;

	bool bSteamReady = false;

	/**
	* Callback result after AttemptCreateLobby is called
	*/
	CCallResult<USteamSubsystem, LobbyCreated_t> m_OnLobbyCreatedResult;
	void OnLobbyCreated(LobbyCreated_t* pResult, bool bIOFailure);
};
