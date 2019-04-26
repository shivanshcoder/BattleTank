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
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);

}

inline void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	TankForward.Z = 0;
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention ).Z;
	IntendTurnRight(RightThrow);
}
