// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;	//We won't be ticked by default 
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())	//	If it's the server, Replicates property(ies) to the Clients.
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}	
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);	//	Transforming TargetLocation from local to GlobalTargetLocation
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	// Call parent class tick function	

	if (HasAuthority())	// If it's the server update property(ies)
	{		
		FVector Location{ GetActorLocation() };	

		//	These are the 2 variable we have to compare to determine when to swap the variables GlobalStartLocation and GlobalTargetLocation
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();	//	The length of the journey that the platform has to take
		float JourneyTravelled = (GlobalStartLocation - Location).Size();	//	The length of how much the platform has travelled

		if (JourneyTravelled >= JourneyLength)
		{
			//	You swap the GlobalStartLocation and GlobalTargetLocation so the platform will comeback
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;			
		}
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += (Speed * DeltaSeconds) * Direction;

		SetActorLocation(Location);
	}		
}
