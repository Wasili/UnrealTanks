// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent {
	GENERATED_BODY()

public:
	void Elevate(float relativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 5.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float minimumElevation = 0.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float maximumElevation = 40.0f;
};
