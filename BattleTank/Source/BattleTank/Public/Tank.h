// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn {
	GENERATED_BODY()

public:
	ATank();
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AimAtLocation(FVector aimLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();

protected:
	UTankAimingComponent* aimingComponent;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetAimingComponentBarrel(UTankBarrel* barrel);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetAimingComponentTurret(UTankTurret* turret);

private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float launchSpeed = 100000.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> projectileBlueprint;

	UTankBarrel* barrelComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float reloadTimeInSeconds = 3.0f;
	float lastFireTime = 0.0f;

};
