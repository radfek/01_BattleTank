// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCannon.h"
#include "Runtime/Engine/Classes/Engine/World.h"



void UTankCannon::Elevate(float RelativeSpeed) {

	//pegar o cannon e girar para a mira vertical, 
	//ter uma velocidade angular deficnida;
	//pegar a direção de turret	   e girar na direção da mira com a vle ang

	//float Time = GetWorld()->GetTimeSeconds();
	// UE_LOG(LogTemp, Warning, TEXT("Time:%f , Elevate relative Speed %f"), Time, RelativeSpeed)
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);	
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;		  //Relative speed between -1 +1/ elevationchange = relative speed ()* velocity(speed/seconds) * time(s)
	float RawNewElevation = (RelativeRotation.Pitch + ElevationChange);
	float Elevation = FMath::Clamp(RawNewElevation, MinElevation, MaxElevation);
	UE_LOG(LogTemp, Error, TEXT(" %f "), Elevation)
	SetRelativeRotation(FRotator(Elevation,0,0));
	
																   
}
