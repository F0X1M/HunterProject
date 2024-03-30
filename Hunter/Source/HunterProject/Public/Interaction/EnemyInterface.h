// Hunter Project copyright.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HUNTERPROJECT_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//Interface

	virtual void ShowEnemyHealthBar() = 0;
	virtual void HideEnemyHealthBar() = 0;
	
	//EndInterface

};
