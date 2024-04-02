// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"

UUIManager* UUIManager::Instance = nullptr;

UUIManager::UUIManager()
{
	
}

UUIManager* UUIManager::Get()
{
	if (Instance == nullptr)
	{
		Instance = NewObject<UUIManager>();
		Instance->AddToRoot(); // Prevent GC

		// Find and assign widget class refs
		AsyncTask(ENamedThreads::GameThread, []() {
			FStringClassReference ErrorDialogueClassRef(TEXT("WidgetBlueprint'/Game/UI/Dialogue/WBP_ErrorDialogue.WBP_ErrorDialogue_C'"));
			FStringClassReference LobbyPlayerListClassRef(TEXT("WidgetBlueprint'/Game/UI/Menu/Lobby/WBP_LobbyPlayerList.WBP_LobbyPlayerList_C'"));

			Instance->SetErrorMessageWidgetClass(ErrorDialogueClassRef.TryLoadClass<UUserWidget>());
			Instance->SetLobbyPlayerListWidgetClass(LobbyPlayerListClassRef.TryLoadClass<UUserWidget>());
		});
	}

	return Instance;
}

UErrorDialogue* UUIManager::GetCurrentErrorDialogue()
{
	return CurrentErrorDialogue;
}

ULobbyPlayerList* UUIManager::GetLobbyPlayerList()
{
	return LobbyPlayerList;
}

void UUIManager::PromptErrorMessage(const FString& Message)
{
	if (CurrentErrorDialogue)
	{
		CurrentErrorDialogue->SetErrorMessageText(Message);

		if (!CurrentErrorDialogue->IsInViewport())
		{
			CurrentErrorDialogue->AddToViewport();
		}

		return;
	}

	CurrentErrorDialogue = CreateWidget<UErrorDialogue>(GetWorld(), ErrorDialogueWidgetClass);

	if (CurrentErrorDialogue)
	{
		CurrentErrorDialogue->SetErrorMessageText(Message);
		CurrentErrorDialogue->AddToViewport();
	}
}

void UUIManager::PromptLobbyPlayerList()
{
	AsyncTask(ENamedThreads::GameThread, [this]() {
		if (LobbyPlayerList)
		{
			UE_LOG(LogTemp, Error, TEXT("LobbyPlayerList conflict"));
			return;
		}

		UWorld* CurrentWorld = GetWorld();
		LobbyPlayerList = CreateWidget<ULobbyPlayerList>(CurrentWorld, LobbyPlayerListWidgetClass); // TODO: LobbyPlayerListWidgetClass is not null, but this fails. Why has god forsaken me

		if (!LobbyPlayerList)
		{
			UE_LOG(LogTemp, Error, TEXT("LobbyPlayerList was not created and assigned"));
			return;
		}

		LobbyPlayerList->AddToViewport();
		LobbyPlayerList->Populate();
	});
}