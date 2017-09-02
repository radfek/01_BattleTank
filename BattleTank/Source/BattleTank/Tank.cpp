// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankCannon.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));	 
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input	   
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)   //TODO nao sei o que isso significa mais
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::SetCannonReference(UTankCannon * CannonToSet)
{
	TankAimingComponent->SetCannonReference(CannonToSet);	
	Cannon = CannonToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::FireProjectile()
{

	bool isReloaded = ((GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds);
	
	if (Cannon && isReloaded) {
		FVector SpawnLocation = Cannon->GetSocketLocation("ProjectileLaunch");
		FRotator SpawnRotation = Cannon->GetSocketRotation("ProjectileLaunch");
		AProjectile* Shoot = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SpawnLocation, SpawnRotation);
		Shoot->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->LogAimTarget(HitLocation, LaunchSpeed);
}