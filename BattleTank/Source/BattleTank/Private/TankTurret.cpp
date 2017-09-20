// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Rotate(float relativeSpeed) {
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0f, 1.0f);
	float elevationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float rawNewRotation = RelativeRotation.Yaw + elevationChange;

	UE_LOG(LogTemp, Warning, TEXT("yaw %f"), relativeSpeed);

	SetRelativeRotation(FRotator(0, rawNewRotation, 0));
}