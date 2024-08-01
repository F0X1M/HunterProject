// Hunter Project copyright.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/HunterAttributeSet.h"

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
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);

	Cast<UHunterAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = Tag.RequestGameplayTag(FName("Message"));
				
				if (Tag.MatchesTag(MessageTag))
				{
					FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
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
