// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();
	virtual void BeginPlay() override;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category = "Default")
	float Speed{ 25.f };
	UPROPERTY(EditAnywhere, Category = "Default", Meta = (MakeEditWidget = true))
	FVector TargetLocation{};

	FVector GlobalStartLocation{};
	FVector GlobalTargetLocation{};

	UPROPERTY(EditAnywhere, Category = "Default")
	int ActiveTriggers{ 1 };
};
