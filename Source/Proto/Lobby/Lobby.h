// G-Spot Enterprises

#pragma once

#include "CoreMinimal.h"
#include "LobbyPlayer.h"
#include "UObject/NoExportTypes.h"
#include "ThirdParty/Steamworks/Steamv153/sdk/public/steam/steam_api.h"
#include "ThirdParty/Steamworks/Steamv153/sdk/public/steam/isteammatchmaking.h"
#include "Lobby.generated.h"

UCLASS()
class PROTO_API ULobby : public UObject
{
	GENERATED_BODY()

public:
	CSteamID GetLobbyID() const { return LobbyID; }
	CSteamID GetLeaderID() const { return LeaderID; }

	void Initialize(const CSteamID& NewLobbyID, const CSteamID& NewLeaderID);

	bool IsLeader(CSteamID& ComparedID) { return LeaderID == ComparedID; }

	TArray<ULobbyPlayer*> GetPlayers();
private:
	CSteamID LobbyID;
	CSteamID LeaderID;
};
