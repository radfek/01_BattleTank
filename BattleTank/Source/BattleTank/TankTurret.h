// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Rotate(float RelativeRotateSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 20.f;


	/*		   Não precisa pois pode rodar livre o turret
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		//In Degrees
		float MaxRotation = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		//In Degrees
		float MinRotation = -2.0f;
		*/
};
	
	

