// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControllerTank() const;
	
	 void BeginPlay() override;
	 virtual void Tick(float DeltaTime) override;

	 //Start the tank moving the barrel so the shot would hit where
		//the cross hair intersect world
	 void AimTowardCrossHair();
	 
	 bool GetSignRayHitLocation(FVector& HitLocation) const;

	 UPROPERTY(EditAnywhere)
	 float CrossHairXLocation = 0.5f;

	 UPROPERTY(EditAnywhere)
	 float CrossHairYLocation = 0.3333333f;

	 bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	 
};
