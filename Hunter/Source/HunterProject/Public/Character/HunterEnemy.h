// Hunter Project copyright.

#pragma once

#include "CoreMinimal.h"
#include "Character/HunterCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "HunterEnemy.generated.h"

/**
 * 
 */
UCLASS()
class HUNTERPROJECT_API AHunterEnemy : public AHunterCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AHunterEnemy();
protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
	
public:
	void ShowEnemyHealthBar() override;
	void HideEnemyHealthBar() override;
};
