// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("player controlled: %s"), *(GetControlledTank()->GetName()));
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {
	ATank* playerTank = GetControlledTank();
	if (!playerTank) {
		return;
	}

	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation)) {
		playerTank->AimAtLocation(hitLocation);
	}

	//check where the crosshair intersects the world
	//rotate the tank barrel towards that point if exists
	//otherwise do nothing
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& outHitLocation) const {
	//find crosshair position in pixel coords
	int32 viewportSizeX, viewportSizeY;
	APlayerController::GetViewportSize(viewportSizeX, viewportSizeY);

	FVector2D screenLocation = FVector2D(crosshairXLocation * viewportSizeX, crosshairYLocation * viewportSizeY);

	//translate screen to world position
	FVector cameraWorldPosition;
	FVector lookDirection;
	if (APlayerController::DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldPosition, lookDirection)) {
		if (GetLookVectorHitLocation(lookDirection, outHitLocation)) {
			return true;
		}
	}
	//line trace along world position
	//see if something is hit by line trace
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector& outHitLocation) const {
	FHitResult hitResult;
	FVector startPosition = PlayerCameraManager->GetCameraLocation();
	if (GetWorld()->LineTraceSingleByChannel(hitResult, startPosition, startPosition + (lookDirection * lineTraceRange), ECollisionChannel::ECC_Visibility)) {		
		outHitLocation = hitResult.Location;
		return true;
	}
	outHitLocation = FVector(0);
	
	return false;
}


