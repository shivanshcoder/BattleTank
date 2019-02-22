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

	TankAimingComponent = CreateEditorOnlyDefaultSubobject< UTankAimingComponent>(FName("AimingComponent"));

	//REMOVE
	//TankMovementComponent = CreateEditorOnlyDefaultSubobject< UTankMovementComponent>(FName("MovementComponent"));
}

void ATank::SetReferences(UTankBarrel * BarrelToSet, UTankTurret *TurretToSet){
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	TankAimingComponent->SetTurretReference(TurretToSet);
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
	TankAimingComponent->AimAt((HitLocaiton),LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

