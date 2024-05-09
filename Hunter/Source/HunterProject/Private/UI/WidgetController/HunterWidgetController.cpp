// Hunter Project copyright.


#include "UI/WidgetController/HunterWidgetController.h"

void UHunterWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UHunterWidgetController::BroadcastInitialValues()
{
	
}

void UHunterWidgetController::BindCallbacksToDependencies()
{
	
}
