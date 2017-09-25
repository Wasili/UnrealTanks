// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTurret.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	aimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAtLocation(FVector aimLocation) {
	aimingComponent->AimAtLocation(aimLocation, launchSpeed);
}

void ATank::Fire() {
	bool isReloaded = (GetWorld()->GetTimeSeconds() - lastFireTime) > reloadTimeInSeconds;

	if (barrelComponent && isReloaded) {

		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(projectileBlueprint,
			barrelComponent->GetSocketLocation(FName("LaunchPoint")),
			barrelComponent->GetSocketRotation(FName("LaunchPoint"))
			);
		projectile->LaunchProjectile(launchSpeed);
		lastFireTime = GetWorld()->GetTimeSeconds();
	}
}

void ATank::SetAimingComponentBarrel(UTankBarrel* barrel) {
	barrelComponent = barrel;
	aimingComponent->SetBarrelComponent(barrel);
}

void ATank::SetAimingComponentTurret(UTankTurret* turret) {
	aimingComponent->SetTurretComponent(turret);
}
