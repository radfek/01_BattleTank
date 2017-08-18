// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController_C.h"




void ATankController_C::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayController Begin Play"))
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("No Pawn is Possesed"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s Olha"), (*ControlledTank->GetName()))
	}
}

// Called every frame
void ATankController_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();
}

ATank* ATankController_C::GetControlledTank() const
{
	 
	return Cast<ATank>(GetPawn());
}

void ATankController_C::AimTowardsCrosshair()
{

	if (!GetControlledTank()) { return; }

	 //Get World location if linetrace throght crosshair
	 //if it hits the landscape or other pawn
		// tell controlled tank to aim at this point

}
