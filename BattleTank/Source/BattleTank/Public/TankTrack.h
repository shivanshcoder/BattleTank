// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force.
 */

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	
	//Set throttle between -1 and +1 
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

private:
	//Max Force per Track
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 4000000 * 10; //40,000kg Mass and Accelearation is 10m/s2
};
