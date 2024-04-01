// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProtoTarget : TargetRules
{
	public ProtoTarget(TargetInfo Target) : base(Target)
	{
		// UE Start
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("Proto");
		// UE End

		// Steamworks Start
		bUsesSteam = true;
        ProjectDefinitions.Add("ONLINE_SUBSYSTEM_EOS_ENABLE_STEAM=1");
        // Steamworks End
    }
}
