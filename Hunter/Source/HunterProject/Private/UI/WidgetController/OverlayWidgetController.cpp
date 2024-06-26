// Hunter Project copyright.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/HunterAttributeSet.h"
#include "UI/Widget/HunterUserWidget.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UHunterAttributeSet* HunterAttributeSet = CastChecked<UHunterAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(HunterAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(HunterAttributeSet->GetMaxHealth());
	OnStaminaChanged.Broadcast(HunterAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(HunterAttributeSet->GetMaxStamina());
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UHunterAttributeSet* HunterAttributeSet = CastChecked<UHunterAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::StaminaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);

	Cast<UHunterAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString()); 
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);

				FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
			}
		}
	);
	
}
	
void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);	
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);	
}

void UOverlayWidgetController::StaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnStaminaChanged.Broadcast(Data.NewValue);	
}

void UOverlayWidgetController::MaxStaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStaminaChanged.Broadcast(Data.NewValue);	
}
