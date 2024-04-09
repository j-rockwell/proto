// G-Spot Enterprises

#include "LobbyPlayer.h"

void ULobbyPlayer::Initialize(const CSteamID& InitSteamID)
{
	SteamID = InitSteamID;
	Name = SteamFriends()->GetFriendPersonaName(InitSteamID);
	Avatar = GetAvatarTexture();
}

FString ULobbyPlayer::GetDisplayName()
{
	return FString(UTF8_TO_TCHAR(Name));
}

UTexture2D* ULobbyPlayer::GetAvatarTexture()
{
	int32 AvatarId = SteamFriends()->GetLargeFriendAvatar(SteamID);
	if (AvatarId == -1) return nullptr;

	uint32 Width, Height;
	if (SteamUtils()->GetImageSize(AvatarId, &Width, &Height))
	{
		TArray<uint8> AvatarRGBA;
		AvatarRGBA.SetNum(Width * Height * 4);

		if (SteamUtils()->GetImageRGBA(AvatarId, AvatarRGBA.GetData(), AvatarRGBA.Num()))
		{
			UTexture2D* AvatarTexture = UTexture2D::CreateTransient(Width, Height, PF_R8G8B8A8);;
			if (AvatarTexture)
			{
				void* TextureData = AvatarTexture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, AvatarRGBA.GetData(), AvatarRGBA.Num());
				AvatarTexture->PlatformData->Mips[0].BulkData.Unlock();
			}

			return AvatarTexture;
		}
	}

	return nullptr;
}