// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankController_C.generated.h"			// must be the las included

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankController_C : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

private:
	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();
};
