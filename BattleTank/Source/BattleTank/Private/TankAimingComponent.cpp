// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include"TankBarrel.h"
#include"TankTurret.h"
#include"Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet) {
	Barrel = (BarrelToSet);
}

void UTankAimingComponent::SetTurretReference(UTankTurret *TurretToSet) {
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocaiton, float LaunchSpeed) {

	//Protecting pointer
	if (!Barrel) return;
	if (!Turret)return;

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
		MoveTurretBarrel(AimDirection);
		auto time = GetWorld()->GetTimeSeconds();
	}
	
}

void UTankAimingComponent::MoveTurretBarrel(FVector AimDirection){
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator =  AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}



