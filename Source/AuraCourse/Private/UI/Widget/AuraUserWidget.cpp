// Copyright Panda Productions


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	if (InWidgetController)
	{
		SetWidgetController(InWidgetController);
		WidgetControllerSet();
	}
	
}
