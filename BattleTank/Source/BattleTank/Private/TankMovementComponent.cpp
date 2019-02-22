// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include"TankTrack.h"




void UTankMovementComponent::IntendMoveForward(float Throw) {
	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::Initialise(UTankTrack * Left, UTankTrack * Right)
{
	//Report error maybe
	if (!Left || !Right) { return; }

	LeftTrack = Left;
	RightTrack = Right;
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("%f Throttle"), Throw)
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);

}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("%f Throttle"), Throw)
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

}
