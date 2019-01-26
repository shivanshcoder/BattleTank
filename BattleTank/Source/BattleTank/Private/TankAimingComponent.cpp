// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include"TankBarrel.h"
#include"Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet) {
	Barrel = Cast<UTankBarrel>(BarrelToSet);
}


void UTankAimingComponent::AimAt(FVector HitLocaiton, float LaunchSpeed) {

	//Protecting pointer
	if (!Barrel) return;

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool HaveDirection = (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocaiton,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace));
	
	if(HaveDirection){
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("Barrel found solution at %f"), time)
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Solution not found "));
	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection){
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator =  AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
}

