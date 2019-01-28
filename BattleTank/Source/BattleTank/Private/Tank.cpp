// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include"TankBarrel.h"
#include"TankTurret.h"
#include"Projectile.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateEditorOnlyDefaultSubobject< UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::SetReferences(UTankBarrel * BarrelToSet, UTankTurret *TurretToSet){
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	TankAimingComponent->SetTurretReference(TurretToSet);
	Barrel = BarrelToSet;
}

void ATank::Fire()
{
	if (!Barrel)return;
	UE_LOG(LogTemp, Warning, TEXT("Fire!!!!!!!"))

		UE_LOG(LogTemp, Warning,TEXT("%s"), *Barrel->GetSocketLocation(FName("Projectile")).ToString())

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);
	Projectile->Launch(LaunchSpeed);
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

