// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include"Public/Tank.h"
#include"GameFramework/Actor.h"
#include"Engine/World.h"
#include"GameFramework/PlayerController.h"


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetPlayerTank();

	if (PlayerTank) {


		MoveToActor(PlayerTank, AcceptanceRadius);

		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
		GetControlledTank()->Fire();
	}
}
