// Hunter Project copyright.


#include "UI/Widget/HunterUserWidget.h"

void UHunterUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
