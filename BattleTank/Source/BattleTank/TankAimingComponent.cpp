// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Classes/Components/StaticMeshComponent.h"





// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::LogAimTarget(FVector AimLocation, float LaunchSpeed)
{
	if (!Cannon) {return;}
	FVector OutLaunchVelocity;
	FVector StartLocation = Cannon->GetSocketLocation(FName("ProjectileLaunch"));

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		AimLocation,
		LaunchSpeed,
		false,
		0.0f,
		10.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
		))
	{
		//Cauculate Out lauch velocity
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();

		UE_LOG(LogTemp, Warning, TEXT("Firing at %s"), *AimDirection.ToString())
	}

	
}

void UTankAimingComponent::SetCannonReference(UStaticMeshComponent * CannonToSet)
{

	Cannon = CannonToSet;
}

