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
	ATank* GetControlledTank();

	void BeginPlay() override;
	

	AActor* ControlledTank;
};
