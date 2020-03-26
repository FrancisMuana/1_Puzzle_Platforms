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
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	// Call parent class tick function	

	if (HasAuthority())	// If it's the server update property(ies)
	{
		FVector Location = GetActorLocation();
		Location += FVector(Speed * DeltaSeconds, 0.0f, 0.0f);

		SetActorLocation(Location);
	}		
}
