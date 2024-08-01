// Hunter Project copyright.

#pragma once

#include "CoreMinimal.h"
#include "Character/HunterCharacterBase.h"
#include "HunterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HUNTERPROJECT_API AHunterCharacter : public AHunterCharacterBase
{
	GENERATED_BODY()

public:
	AHunterCharacter();

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

private:
	virtual void InitAbilityActorInfo() override;

public:
	float BulletRange = 2500.f;
};
