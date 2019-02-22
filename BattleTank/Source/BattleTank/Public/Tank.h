// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocaiton);

	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetReferences(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);


	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

protected:
	UTankAimingComponent *TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile>ProjectileBlueprint;


	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000.0f;


	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSec = 3;

	//Saving Local Reference for spawning
	UTankBarrel *Barrel = nullptr;

	double LastTimeFire = 0;
};
