// Hunter Project copyright.


#include "Character/HunterEnemy.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/HunterAttributeSet.h"

AHunterEnemy::AHunterEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHunterAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UHunterAttributeSet>("AttributeSet");
}

void AHunterEnemy::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}

void AHunterEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UHunterAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

void AHunterEnemy::ShowEnemyHealthBar()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy"));
}

void AHunterEnemy::HideEnemyHealthBar()
{
	UE_LOG(LogTemp, Warning, TEXT("Nie Enemy"));
}
