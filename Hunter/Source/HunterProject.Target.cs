// Hunter Project copyright.

using UnrealBuildTool;
using System.Collections.Generic;

public class HunterProjectTarget : TargetRules
{
	public HunterProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "HunterProject" } );
	}
}
