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

ATank* ATankController_C::GetControlledTank()
{
	 
	return Cast<ATank>(GetPawn());
}