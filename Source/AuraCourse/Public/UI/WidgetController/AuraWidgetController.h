// Copyright Panda Productions

#pragma once

#include "CoreMinimal.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

/**
 * 
 */

class UAuraAttributeSet;
class UAuraAbilitySystemComponent;


UCLASS()
class AURACOURSE_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<AAuraPlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<AAuraPlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAuraAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAuraAttributeSet> AttributeSet;

	
	
};
