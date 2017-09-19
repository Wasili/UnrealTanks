// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::AimAtLocation(FVector aimLocation, float launchSpeed) {
	if (!barrelComponent) {
		return;
	}

	FVector launchVelocity;
	FVector startLocation = barrelComponent->GetSocketLocation(FName("LaunchPoint"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, launchVelocity, startLocation, aimLocation, launchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace)) {
		FVector aimDirection = launchVelocity.GetSafeNormal();
		AimBarrelTowards(aimDirection);
	}
}

void UTankAimingComponent::SetBarrelComponent(UTankBarrel* barrel) {
	barrelComponent = barrel;
}

void UTankAimingComponent::AimBarrelTowards(FVector aimDirection) {
	FRotator barrelRotation = barrelComponent->GetForwardVector().Rotation();
	FRotator aimAsRotation = aimDirection.Rotation();

	FRotator deltaRotation = aimAsRotation - barrelRotation;
	barrelComponent->Elevate(5);
}

