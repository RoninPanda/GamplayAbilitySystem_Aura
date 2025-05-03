// Copyright Panda Productions

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraCourseTarget : TargetRules
{
	public AuraCourseTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AuraCourse" } );
	}
}
