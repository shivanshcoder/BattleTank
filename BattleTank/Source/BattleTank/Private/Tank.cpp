// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include"TankBarrel.h"
#include"TankTurret.h"
#include"Projectile.h"
#include "TankAimingComponent.h"
#include"TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("Horse: Atank Constructor!"))

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Horse: Begin Play!"))

}

void ATank::SetReferences(UTankAimingComponent* AimingComp, UTankBarrel* BarrelToSet, UTankTurret* TurretToSet) {
	TankAimingComponent = AimingComp;
	TankAimingComponent->Initialise(BarrelToSet, TurretToSet);
	Barrel = BarrelToSet;
}


void ATank::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastTimeFire) > ReloadTimeInSec;
	if (Barrel && IsReloaded) {

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->Launch(LaunchSpeed);
		LastTimeFire = FPlatformTime::Seconds();
	}
}


void ATank::AimAt(FVector HitLocaiton) {
	if (TankAimingComponent)
		TankAimingComponent->AimAt((HitLocaiton), LaunchSpeed);
}




