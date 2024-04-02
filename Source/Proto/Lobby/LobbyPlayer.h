// G-Spot Enterprises

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ThirdParty/Steamworks/Steamv153/sdk/public/steam/steam_api.h"
#include "ThirdParty/Steamworks/Steamv153/sdk/public/steam/isteammatchmaking.h"
#include "LobbyPlayer.generated.h"

UCLASS()
class PROTO_API ULobbyPlayer : public UObject
{
	GENERATED_BODY()

public:
	void Initialize(const CSteamID& InitSteamID);

	CSteamID GetSteamID() { return SteamID; }
	const char* GetName() { return Name; }
	UTexture2D* GetAvatar() { return Avatar; }
	FString GetDisplayName();

private:
	CSteamID SteamID;
	const char* Name;
	UTexture2D* Avatar;
	UTexture2D* GetAvatarTexture();
};