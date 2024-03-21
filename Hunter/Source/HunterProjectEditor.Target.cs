// Hunter Project copyright.

using UnrealBuildTool;
using System.Collections.Generic;

public class HunterProjectEditorTarget : TargetRules
{
	public HunterProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "HunterProject" } );
	}
}
