// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"




void UTankTurret::Rotate(float RelativeRotateSpeed) {

	RelativeRotateSpeed = FMath::Clamp<float>(RelativeRotateSpeed, -1, +1);
	float RotationChange = RelativeRotateSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;		  //Relative speed between -1 +1/ elevationchange = relative speed ()* velocity(speed/seconds) * time(s)
	float Rotation = (RelativeRotation.Yaw + RotationChange);
	//float Elevation = FMath::Clamp(RawNewRotation, MinRotation, Max); // dont need
	//UE_LOG(LogTemp, Error, TEXT(" Este é o novo dado calculado %f "), Rotation)
	SetRelativeRotation(FRotator(0, Rotation, 0));

}

