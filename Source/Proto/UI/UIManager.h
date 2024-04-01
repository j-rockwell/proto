// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Dialogue/ErrorDialogue.h"
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
	void PromptErrorMessage(const FString& Message);
	UErrorDialogue* GetCurrentErrorDialogue();
	// Error Dialogue End
private:
	static UUIManager* Instance;

	UErrorDialogue* CurrentErrorDialogue;
	TSubclassOf<UUserWidget> ErrorDialogueWidgetClass;
};