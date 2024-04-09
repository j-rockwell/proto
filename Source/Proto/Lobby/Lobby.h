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
	/**
	* Return the lobbies CSteamID
	*/
	CSteamID GetLobbyID() const { return LobbyID; }

	/**
	* Return the leader's CSteamID
	*/
	CSteamID GetLeaderID() const { return LeaderID; }

	/**
	* Initialize sets initial values for the
	* new lobby instance.
	*/
	void Initialize(const CSteamID& NewLobbyID, const CSteamID& NewLeaderID);

	/**
	* IsLeader returns true if the provided CSteamID
	* matches the creator of the lobbies ID
	*/
	bool IsLeader(CSteamID& ComparedID) { return LeaderID == ComparedID; }

	/**
	* GetPlayers returns an array of Lobby Player
	* objects that contain important details to
	* properly display player information in the
	* lobby UI
	*/
	TArray<ULobbyPlayer*> GetPlayers();
private:
	CSteamID LobbyID;
	CSteamID LeaderID;
};
