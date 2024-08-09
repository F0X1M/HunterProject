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

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);	
		}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnStaminaChanged.Broadcast(Data.NewValue);
		}
		);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HunterAttributeSet->GetMaxStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxStaminaChanged.Broadcast(Data.NewValue);
		}
		);

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
