// Fill out your copyright notice in the Description page of Project Settings.


#include "ErrorDialogue.h"

void UErrorDialogue::SetErrorMessageText(const FString& ErrorMessage)
{
	ErrorMessageText->SetText(FText::FromString(ErrorMessage));
}