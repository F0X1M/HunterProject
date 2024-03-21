// Hunter Project copyright.


#include "Character/HunterCharacterBase.h"

AHunterCharacterBase::AHunterCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AHunterCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHunterCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHunterCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

