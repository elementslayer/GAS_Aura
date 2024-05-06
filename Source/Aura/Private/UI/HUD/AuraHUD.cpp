// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/Widget/OverlayWidgetController.h"
#include "UI/Widget/AttributeMenuWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if(OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParam(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParam(WCParams);
		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}
	return AttributeMenuWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay WIdget Class unitiazlied. Fill Out BP_Aura_HUD"))
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class Uninitalized, Fill Out BP_Aura_HUD"))

	UUserWidget* TmpOverlayWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(TmpOverlayWidget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);

	UOverlayWidgetController* TmpOverlayWidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(TmpOverlayWidgetController);
	TmpOverlayWidgetController->BroadcastInitialValues();

	TmpOverlayWidget->AddToViewport();
}
