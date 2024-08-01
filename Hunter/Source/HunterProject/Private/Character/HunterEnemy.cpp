// Hunter Project copyright.


#include "Character/HunterEnemy.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/HunterAttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"

AHunterEnemy::AHunterEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UHunterAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UHunterAttributeSet>("AttributeSet");

	HealthBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBarCoomponent"));
	HealthBarWidget->SetupAttachment(RootComponent);
	HealthBarWidget->SetWidgetSpace(EWidgetSpace::World);
	HealthBarWidget->SetDrawSize(FVector2D(100.f,10.f));
	HealthBarWidget->SetWorldLocation(GetCapsuleComponent()->GetComponentLocation()+ GetActorUpVector() * (GetCapsuleComponent()->GetScaledCapsuleHalfHeight()*1.5f));
	HealthBarWidget->SetVisibility(false);
	
}

void AHunterEnemy::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
	
}

void AHunterEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	PlayerLocation = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();
	HealthBarWidget->SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(HealthBarWidget->GetComponentLocation(),PlayerLocation));
	
}

void AHunterEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UHunterAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

void AHunterEnemy::ShowEnemyHealthBar()
{
	HealthBarWidget->SetVisibility(true);
	
}

void AHunterEnemy::HideEnemyHealthBar()
{
	HealthBarWidget->SetVisibility(false);
}
