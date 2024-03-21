// Hunter Project copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HunterCharacterBase.generated.h"

UCLASS()
class HUNTERPROJECT_API AHunterCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AHunterCharacterBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
