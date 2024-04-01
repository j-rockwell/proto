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
		FStringClassReference ErrorDialogueClassRef(TEXT("WidgetBlueprint'/Game/UI/Dialogue/WBP_ErrorDialogue.WBP_ErrorDialogue_C'"));
		UClass* ErrorDialogueWidgetClass = ErrorDialogueClassRef.TryLoadClass<UUserWidget>();
	}

	return Instance;
}

UErrorDialogue* UUIManager::GetCurrentErrorDialogue()
{
	return CurrentErrorDialogue;
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