// Copyright Panda Productions

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChagedSignature, float, NewValue);


/**
 * 
 */
USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Message = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UAuraUserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* MessageImage = nullptr;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

UCLASS(BlueprintType, Blueprintable)
class AURACOURSE_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;
	

	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnAttributeChagedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnAttributeChagedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnAttributeChagedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnAttributeChagedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "Gas | Attributes")
	FMessageWidgetRowSignature MessageWidgetRow;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WidgetData")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* InDataTable, const FGameplayTag& InTag);
};

template <typename T>
T* UOverlayWidgetController::GetDataTableRowByTag(UDataTable* InDataTable, const FGameplayTag& InTag)
{
	return InDataTable->FindRow<T>(InTag.GetTagName(), TEXT(""));
}
