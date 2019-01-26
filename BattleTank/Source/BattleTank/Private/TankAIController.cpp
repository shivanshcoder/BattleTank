// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include"Public/Tank.h"
#include"GameFramework/Actor.h"
#include"Engine/World.h"
#include"GameFramework/PlayerController.h"


ATank * ATankAIController::GetPlayerTank() const {
	auto tmpPtr = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (tmpPtr)
		return Cast<ATank>(tmpPtr);
	return nullptr;
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AiController Begin Play!"));

	auto targetTank = GetPlayerTank();

	if (targetTank)
		UE_LOG(LogTemp, Warning, TEXT("Player Tank %s "), *targetTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found"))


		auto ptrTank = GetControlledTank();

	if (ptrTank)
		UE_LOG(LogTemp, Warning, TEXT("Tank %s Possessed"), *ptrTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("Tank not found"))
}
