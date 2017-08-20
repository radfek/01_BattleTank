// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController_C.h"
//#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"



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
	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation)) 
	{
		GetControlledTank()->AimAt(HitLocation);
	}
			
}

bool ATankController_C::GetSightRayHitLocation(FVector &HitLocation) //Get World location of linetrace trhoght crossgair , true if it hit the landscape
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D (CrossHairXLocation*ViewportSizeX, CrossHairYLocation*ViewportSizeY);
	//Get aim direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		if (GetLookVectorHitLocation(LookDirection, HitLocation)) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
	
}

bool ATankController_C::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	FVector CameraWorldLocation;   // to be discarded
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection))
	{	return true;}
	else { return false; }
}

bool ATankController_C::GetLookVectorHitLocation(FVector & LookDirection, FVector & HitLocation) const
{
	FHitResult Hit;
	FVector TraceEnd,TraceStart;
	TraceStart = PlayerCameraManager->GetCameraLocation();
	TraceEnd = TraceStart + LineTraceRange*LookDirection;
	if (GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility))
	{
		HitLocation = Hit.Location;
		//UE_LOG(LogTemp, Warning, TEXT("ItWorks %s"), (*HitLocation.ToString()))
			return true;
	}
	else
	{ 
		HitLocation = FVector(0);
		return false;
	}

}
