// Hunter Project copyright.


#include "Character/HunterCharacter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/HunterPlayerController.h"
#include "Player/HunterPlayerState.h"

AHunterCharacter::AHunterCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = false;
	GetCharacterMovement()->bSnapToPlaneAtStart = false;
	
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;	
	bUseControllerRotationRoll = false;
}

void AHunterCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void AHunterCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

void AHunterCharacter::InitAbilityActorInfo()
{
	AHunterPlayerState* HunterPlayerState = GetPlayerState<AHunterPlayerState>();
	check(HunterPlayerState);
	HunterPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(HunterPlayerState, this);
	Cast<UHunterAbilitySystemComponent>(HunterPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	
	AbilitySystemComponent = HunterPlayerState->GetAbilitySystemComponent();
	AttributeSet = HunterPlayerState->GetAttributeSet();

	//Inicjacja HUD
	/*if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}*/
}
