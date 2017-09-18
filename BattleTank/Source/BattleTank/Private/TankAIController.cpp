// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* playerTank = GetPlayerTank();
	if (playerTank == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Player not found"));
	}
}

void ATankAIController::Tick(float DeltaTime) {
	ATank* playerTank = GetPlayerTank();
	ATank* controlledTank = GetControlledTank();
	if (playerTank && controlledTank) {
		controlledTank->AimAtLocation(playerTank->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
