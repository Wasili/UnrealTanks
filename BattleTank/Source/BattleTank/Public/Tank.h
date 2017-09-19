// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AimAtLocation(FVector aimLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetAimingComponentBarrel(UTankBarrel* barrel);

protected:
	UTankAimingComponent* aimingComponent;

private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float launchSpeed = 100000.0f;
		
};
