// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayeController Begin Play!"));

	auto ptrTank = Cast<ATank>(GetPawn());
	if (ptrTank)
		UE_LOG(LogTemp, Warning, TEXT("Tank %s Possessed"), *ptrTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("Tank not found"))
}
