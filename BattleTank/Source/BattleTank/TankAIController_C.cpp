// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController_C.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"




void ATankAIController_C::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank * ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetTargetLocation());
		ControlledTank->FireProjectile(); //TODO dont fire every frame
	}

		
}

