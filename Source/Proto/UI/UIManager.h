// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Dialogue/ErrorDialogue.h"
#include "Menu/LobbyPlayerList.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class PROTO_API UUIManager : public UObject
{
	GENERATED_BODY()

public:
	UUIManager();

	static UUIManager* Get();

	// Error Dialogue Start
	void SetErrorMessageWidgetClass(TSubclassOf<UUserWidget> WidgetClass) { ErrorDialogueWidgetClass = WidgetClass; }
	void PromptErrorMessage(const FString& Message);
	UErrorDialogue* GetCurrentErrorDialogue();
	// Error Dialogue End

	// Lobby Player List Start
	void SetLobbyPlayerListWidgetClass(TSubclassOf<UUserWidget> WidgetClass) { LobbyPlayerListWidgetClass = WidgetClass; }
	void PromptLobbyPlayerList();
	ULobbyPlayerList* GetLobbyPlayerList();
	// Lobby Player List Stop
private:
	static UUIManager* Instance;

	// Error Dialogue Start
	UErrorDialogue* CurrentErrorDialogue;
	TSubclassOf<UUserWidget> ErrorDialogueWidgetClass;
	// Error Dialogue Stop

	// Lobby Player List Start
	ULobbyPlayerList* LobbyPlayerList;
	TSubclassOf<UUserWidget> LobbyPlayerListWidgetClass;
	// Lobby Player List Stop
};