// G-Spot Enterprises


#include "Lobby.h"

void ULobby::Initialize(const CSteamID& NewLobbyID, const CSteamID& NewLeaderID)
{
	LobbyID = NewLobbyID;
	LeaderID = NewLeaderID;
}

TArray<ULobbyPlayer*> ULobby::GetPlayers()
{
    TArray<ULobbyPlayer*> result;

    int totalMemberCount = SteamMatchmaking()->GetNumLobbyMembers(LobbyID);
    for (int i = 0; i < totalMemberCount; i++)
    {
        CSteamID memberId = SteamMatchmaking()->GetLobbyMemberByIndex(LobbyID, i);
        ULobbyPlayer* lobbyPlayer = NewObject<ULobbyPlayer>(this, ULobbyPlayer::StaticClass());
        lobbyPlayer->Initialize(memberId);
        result.Add(lobbyPlayer);
    }

    return result;
}