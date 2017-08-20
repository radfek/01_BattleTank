// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController_C.h"




void ATankAIController_C::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"))
		auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("AI can't find player tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s Olha"), (*PlayerTank->GetName()))
	}
}

void ATankAIController_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) 
	{
		AimTowardsPlayer();
	}
}


ATank* ATankAIController_C::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController_C::GetPlayerTank() const
{
	return Cast<ATank> (GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController_C::AimTowardsPlayer()
{
	FVector EnemyLocation = GetPlayerTank()->GetTargetLocation();
	GetAIControlledTank()->AimAt(EnemyLocation);
}

