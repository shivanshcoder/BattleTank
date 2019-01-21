// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay()override;
	virtual void Tick(float DeltaTime)override;

	bool GetSightRayHitLocation(FVector &HitLocation)const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection)const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;


	void AimTowardsCrosshair();

	ATank* GetControlledTank()const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation  = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;
};
