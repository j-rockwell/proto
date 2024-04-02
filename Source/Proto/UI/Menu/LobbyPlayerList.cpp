#include "LobbyPlayerList.h"
#include "../../System/ProtoGameInstance.h"
#include "../../System/Subsystems/SteamSubsystem.h"
#include "../../Lobby/Lobby.h"

void ULobbyPlayerList::NativeConstruct()
{
	Super::NativeConstruct();

    PlayerNames.Empty();
    PlayerAvatars.Empty();

    for (int32 i = 0; i < 32; i++) // TODO: Find better way than 32 iterations or loop break?
    {
        FName PlayerName = FName(*FString::Printf(TEXT("PlayerName_%d"), i));
        FName PlayerAvatar = FName(*FString::Printf(TEXT("PlayerAvatarImage_%d"), i));

        UTextBlock* TextBlock = Cast<UTextBlock>(GetWidgetFromName(PlayerName));
        UImage* AvatarImage = Cast<UImage>(GetWidgetFromName(PlayerAvatar));

        if (!TextBlock || !AvatarImage) break;

        PlayerNames.Add(TextBlock);
        PlayerAvatars.Add(AvatarImage);
;    }

    UE_LOG(LogTemp, Log, TEXT("Loaded Player List Widgets - Player Names: %i, Player Avatar: %i"), PlayerNames.Num(), PlayerAvatars.Num());
}

void ULobbyPlayerList::Populate()
{
    UWorld* World = GEngine->GameViewport->GetWorld();
    UProtoGameInstance* ProtoGameInstance = Cast<UProtoGameInstance>(World->GetGameInstance());
    USteamSubsystem* Steam = ProtoGameInstance->GetSubsystem<USteamSubsystem>();
    ULobby* LobbyInstance = Steam->GetLobby();

    if (LobbyInstance)
    {
        TArray<ULobbyPlayer*> Players = LobbyInstance->GetPlayers();
        for (int i = 0; i < Players.Num(); i++)
        {
            ULobbyPlayer* Player = Players[i];
            SetPlayer(i, Player->GetDisplayName(), Player->GetAvatar());
        }
    }
}

void ULobbyPlayerList::SetPlayer(int32 Index, const FString& Username, UTexture2D* Avatar)
{
    UTextBlock* TargetTextBlock = PlayerNames[Index];
    UImage* TargetImage = PlayerAvatars[Index];

    if (!TargetTextBlock)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to find target Text Block"));
        return;
    }

    if (!TargetImage)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to find target Image Block"));
        return;
    }

    TargetTextBlock->SetText(FText::FromString(Username));
    TargetImage->SetBrushFromTexture(Avatar, false);
}

void ClearPlayer(int32 Index)
{

}