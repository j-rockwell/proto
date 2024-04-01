// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ErrorDialogue.generated.h"

UCLASS()
class PROTO_API UErrorDialogue : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "UI|Dialogue|Error")
	void SetErrorMessageText(const FString& Message);

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ErrorMessageText;
};
