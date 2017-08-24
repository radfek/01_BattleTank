// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankController_C.generated.h"			// must be the last included


/**
*
*/

class ATank; //Foward Declaration
UCLASS()
class BATTLETANK_API ATankController_C : public APlayerController
{
	GENERATED_BODY()
	
private:
	
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;


	ATank* GetControlledTank() const;
	bool GetSightRayHitLocation(FVector &HitLocation);
	void AimTowardsCrosshair();
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const;
	//VAriables
	UPROPERTY(EditAnywhere)
	float	CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float	CrossHairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
	int32	LineTraceRange = 1000000; // range 10km
		
};
