// G-Spot Enterprises

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Blueprint/UserWidget.h"
#include "LobbyPlayerList.generated.h"

UCLASS()
class PROTO_API ULobbyPlayerList : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	* Populate reads current Lobby Instance data
	* and populates any widgets with data upon
	* initial widget creation
	*/
	void Populate();

	/**
	* SetPlayer populates a slot in the player list
	* with the provided username and avatar information
	*/
	void SetPlayer(int32 Index, const FString& Username, UTexture2D* Avatar);

	/**
	* ClearPlayer removes an entry in the UI at the
	* provided index position.
	*/
	void ClearPlayer(int32 Index);

protected:
	virtual void NativeConstruct() override;

	UTextBlock* LobbyTitleText;
	TArray<UTextBlock*> PlayerNames;
	TArray<UImage*> PlayerAvatars;
};

