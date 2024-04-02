// G-Spot Enterprises

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MainMenuBridge.generated.h"

/**
 * 
 */
UCLASS()
class PROTO_API UMainMenuBridge : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI|Menu")
	static void OnSingleplayerPress();

	UFUNCTION(BlueprintCallable, Category = "UI|Menu")
	static void OnCreditsPress();

	UFUNCTION(BlueprintCallable, Category = "UI|Menu")
	static void OnMultiplayerPress();
};
