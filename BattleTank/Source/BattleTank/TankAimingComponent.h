// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "CoreMinimal.h"

#include "Classes/Components/StaticMeshComponent.h"

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void LogAimTarget(FVector AimLocation, float LaunchSpeed);

	void SetCannonReference(UStaticMeshComponent* CannonToSet);

private:
	UStaticMeshComponent* Cannon = nullptr;
	
};
