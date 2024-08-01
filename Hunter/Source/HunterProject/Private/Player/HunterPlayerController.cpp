// Hunter Project copyright.


#include "Player/HunterPlayerController.h"

#include "CollisionDebugDrawingPublic.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "KismetTraceUtils.h"
#include "GameFramework/Character.h"
#include "Interaction/EnemyInterface.h"

AHunterPlayerController::AHunterPlayerController()
{
	bReplicates = true;
}

void AHunterPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	AimTrace();
}

void AHunterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(HunterContext, 0);
	}

	PlayerCamera = this->PlayerCameraManager;

	check(PlayerCamera);

	ControlledCharacter = Cast<AHunterCharacter>(GetPawn());
}

void AHunterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHunterPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHunterPlayerController::Look);
	
}

void AHunterPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{		
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AHunterPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
	
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
	
}

void AHunterPlayerController::AimTrace()
{
	FVector Start = PlayerCamera->GetCameraLocation();
	FVector End = Start + (GetPawn<APawn>()->GetActorForwardVector() * ControlledCharacter->BulletRange);

	FHitResult TargetHit;
	GetWorld()->LineTraceSingleByChannel(TargetHit, Start, End, ECC_Visibility);

	if (!TargetHit.bBlockingHit) return;
	
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(TargetHit.GetActor());
	
	if (LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			ThisActor->ShowEnemyHealthBar();
		}
	}
	else
	{
		if(ThisActor == nullptr)
		{
			LastActor->HideEnemyHealthBar();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				LastActor->HideEnemyHealthBar();
				ThisActor->ShowEnemyHealthBar();
			}
		}
	}

	
	/* Strzał linetrace ### DONE
	 * Dostosowań linetrace do zmieniającej się odległosci ### DONE
	 * sprawdzanie czy to przeciwnik 
	 * wywołujemy funkcję
	*/
	//DrawDebugLineTraceSingle(GetWorld(), Start, End, EDrawDebugTrace::ForDuration, false, HitResult, FColor::Red, FColor::Blue, 0.1);
}


