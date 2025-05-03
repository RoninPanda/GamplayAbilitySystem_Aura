// Copyright Panda Productions

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraCourseEditorTarget : TargetRules
{
	public AuraCourseEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AuraCourse" } );
	}
}
