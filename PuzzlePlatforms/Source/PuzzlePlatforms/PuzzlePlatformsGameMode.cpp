// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PuzzlePlatformsGameMode.h"
#include "PuzzlePlatformsCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"		// For UGameplayStatics
#include "Engine/World.h"				// For GetWorld
#include "Engine.h"						// for GEngine


APuzzlePlatformsGameMode::APuzzlePlatformsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}	
}

void APuzzlePlatformsGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GEngine->GetFirstLocalPlayerController(GetWorld()), 0);
	if (PlayerController)	//	if playercontroller index 0 is valid
	{
		UGameplayStatics::RemovePlayer(PlayerController, true);	//	remove the playercontroller index "0" and its pawn
	}	
}
