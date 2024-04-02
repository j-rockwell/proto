// G-Spot Enterprises

#include "MainMenuBridge.h"
#include "../../System/ProtoGameInstance.h"
#include "../../System/Subsystems/SteamSubsystem.h"

void UMainMenuBridge::OnSingleplayerPress()
{

}

void UMainMenuBridge::OnMultiplayerPress()
{
	UE_LOG(LogTemp, Display, TEXT("OnMultiplayerPress called"));
	UWorld* World = GEngine->GameViewport->GetWorld();
	UProtoGameInstance* ProtoGameInstance = Cast<UProtoGameInstance>(World->GetGameInstance());
	USteamSubsystem* Steam = ProtoGameInstance->GetSubsystem<USteamSubsystem>();
	Steam->AttemptCreateLobby();
}

void UMainMenuBridge::OnCreditsPress()
{

}