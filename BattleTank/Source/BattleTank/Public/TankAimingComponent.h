// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;//Forward Declaration
class UTankTurret;

UENUM()
enum class EFiringStatus : uint8 {
	Locked,
	Aiming,
	Reloading
};

//Holds Barrel Properties!!
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocaiton, float LaunchSpeed);

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void MoveTurretBarrel(FVector AimDirection);

	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;

protected:
	UPROPERTY(BlueprintReadOnly, Category="State")
	EFiringStatus FiringState = EFiringStatus::Aiming;
};
