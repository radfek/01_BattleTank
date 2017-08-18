// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController_C.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController_C : public AAIController
{
	GENERATED_BODY()
	
	
public:	  
	void BeginPlay() override;
private:
	ATank* GetAIControlledTank() const;
	ATank* GetPlayerTank() const ;
	//APawn* GetPlayerPawn() const;
	
};
