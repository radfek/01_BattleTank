// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController_C.generated.h"

/**
 * 
 */
class ATank; //Foward declaration
UCLASS()
class BATTLETANK_API ATankAIController_C : public AAIController
{
	GENERATED_BODY()
	
	
public:	  
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	
	
};
