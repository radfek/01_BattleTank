// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Runtime/Engine/Classes/Engine/World.h"




void UTankTrack::SetThrottle(float Throttle) {

	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp,Warning, TEXT("%s Throttle %f "), *Name, Throttle)

}