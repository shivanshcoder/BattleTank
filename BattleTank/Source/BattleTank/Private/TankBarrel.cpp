// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);

	auto ElevationChange = RelativeSpeed * MaxDegreePerSec*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	RawNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation );
	//UE_LOG(LogTemp, Error, TEXT("%f RawElevation"), )
		SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}
