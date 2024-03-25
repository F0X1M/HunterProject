// Hunter Project copyright.


#include "Player/HunterPlayerState.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/HunterAttributeSet.h"

AHunterPlayerState::AHunterPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UHunterAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHunterAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AHunterPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
