// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Ticking!"));
	AimTowardsCrosshair();
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation)const {

	//Get the croshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation;
	ScreenLocation.X = ViewportSizeX * CrossHairXLocation;
	ScreenLocation.Y = ViewportSizeY * CrossHairYLocation;

	FVector WorldDirection;
	if (GetLookDirection(ScreenLocation, WorldDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Direction of the CrossHair: %s"), *WorldDirection.ToString())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Error"))
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector WorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);

}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
		return;

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());
	}
}

ATank* ATankPlayerController::GetControlledTank()const {
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayeController Begin Play!"));

	auto ptrTank = GetControlledTank();

	if (ptrTank)
		UE_LOG(LogTemp, Warning, TEXT("Tank %s Possessed"), *ptrTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("Tank not found"))

}
