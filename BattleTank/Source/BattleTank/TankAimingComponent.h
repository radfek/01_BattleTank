// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankCannon; //foward declaration  (instead of #include TankCannon.h here we to it in .cpp - this makes stuff faster)
class UTankTurret;


// Holds cannon's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:


public:	

	void LogAimTarget(FVector AimLocation, float LaunchSpeed);

	void SetCannonReference(UTankCannon* CannonToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void MoveTurretAndCannon(FVector AimDirection);


private:
	UTankCannon* Cannon = nullptr;
	
	UTankTurret* Turret = nullptr;
};
