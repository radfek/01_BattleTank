// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankCannon.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankCannon : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// - 1 is max downward speed, and +1 is max upwards speed
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	//In Degrees
	float MaxElevation = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	//In Degrees
	float MinElevation = -2.0f;
};
