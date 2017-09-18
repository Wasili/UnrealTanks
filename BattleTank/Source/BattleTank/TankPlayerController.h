// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTank/Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController {
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	void BeginPlay() override;
private:
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& outHitLocation) const;
	bool GetLookVectorHitLocation(FVector lookDirection, FVector& outHitLocation) const;

	FVector2D aimPoint;

	UPROPERTY(EditAnywhere)
		float crosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float crosshairYLocation = 0.33333f;
	UPROPERTY(EditAnywhere)
		float lineTraceRange = 1000000.0f;
};
