// Hunter Project copyright.


#include "Character/HunterCharacterBase.h"

AHunterCharacterBase::AHunterCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

UAbilitySystemComponent* AHunterCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AHunterCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

