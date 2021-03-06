// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"Public/Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 *
 */
class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	ATank* GetControlledTank()const{
		return Cast<ATank>(GetPawn());	
	}

	ATank* GetPlayerTank()const {
		return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}

	virtual void Tick(float DeltaTime)override;

	//How close can the AI tank can get
	float AcceptanceRadius = 3000;

};
