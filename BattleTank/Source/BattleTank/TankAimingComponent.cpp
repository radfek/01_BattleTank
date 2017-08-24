// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankCannon.h"
#include "Classes/Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;				     //TODO Should this realy tick?


	// ...
}
void UTankAimingComponent::LogAimTarget(FVector AimLocation, float LaunchSpeed)
{
	if (!Cannon) {return;}
	FVector OutLaunchVelocity;
	FVector StartLocation = Cannon->GetSocketLocation(FName("ProjectileLaunch"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		AimLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace

	);
	if (bHaveAimSolution)
	{

		//Cauculate Out lauch velocity
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveCannon (AimDirection);	
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("Time:%f  Aim Solution found"), Time)
	}
	else {
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Error, TEXT("Time:%f  NotFound"), Time)

		//log stuff to know 
	}
}

void UTankAimingComponent::SetCannonReference(UTankCannon * CannonToSet)  //Called by a blueprint->TAnk_BP
{
	Cannon = CannonToSet;
}

void UTankAimingComponent::MoveCannon(FVector AimDirection)
{

	FRotator CannonRotator = Cannon->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotatoe = AimAsRotator - CannonRotator;
	UE_LOG(LogTemp, Warning, TEXT("cannon rotator: %s Aim rotator: %s"), *CannonRotator.ToString(), *AimAsRotator.ToString())
	
	Cannon->Elevate(1);

}

