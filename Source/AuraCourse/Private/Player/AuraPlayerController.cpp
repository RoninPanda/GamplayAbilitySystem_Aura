// Copyright Panda Productions


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include  "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
	CursorTrace();
	

	
}
void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;

	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	if (!CursorHit.bBlockingHit)
		return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();



	/**
	 *	Line trace from cursor. There are several scenarios
	 *	A. LastActor is Null & ThisActor is Null
	 *		- Do Nothing
	 *	B. LastActor Is Null & ThisActor Is Valid
	 *		- Highlight ThisActor
	 *	C. Last Actor Is Valid & ThisActor Is Null
	 *		- Remove The Highlight, UnHighlight LastActor
	 *	D.LastActor Is Valid & ThisActor Is Valid But LastActor != ThisActor
	 *		- Remove the HighLight On Last Actor Then Highlight ThisActor
	 *	E. LastActor And This Actor Are Valid and LastActor = ThisActor
	 *		- Do Nothing
	 *
	 */

	/*if (LastActor  == nullptr)
	{
		if (ThisActor != nullptr)
		{
			//Case B
		}else
		{
			//Case A
		}
	}
	else //lastActor Is Valid But THis Actor is Null
	{
		if (ThisActor == nullptr)
		{
			//Case C
		} else //both actors are valid
		{
			if (LastActor != ThisActor)
			{
				//Case D
			}else
			{
				//Case E
			}
		}
	}
*/

	if (LastActor != ThisActor )
	{
		if (LastActor)
			LastActor->UnHighlightActor();

		if (ThisActor)
			ThisActor->HighlightActor();
	}
	
}


void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection =  FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection =  FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
	
}


