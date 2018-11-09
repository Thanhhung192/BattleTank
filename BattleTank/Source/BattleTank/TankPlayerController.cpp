// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControllerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn %s"), *ControlledTank->GetName());
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Aim toward Cross hair
	AimTowardCrossHair();
}

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrossHair()
{
	if (!GetControllerTank()){return;}
	
	FVector HitLocation; //OUT parameter
	if (GetSignRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction %s"), *HitLocation.ToString());
		
		//TODO Tell controlled tank to aim at this point
	}	
	return;
}

//GetWorldLocation of line trace through cross hair true if hit landscape
bool ATankPlayerController::GetSignRayHitLocation(FVector& HitLocation) const
{
	//Set cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction %s"), *LookDirection.ToString());
	}
		//De project the screen position of the cross hair to a world direction
			//line trace along that look direction, see what we hit (in a range)
				//if line trace hit landscape
					//Get OutHitLocation
		HitLocation = FVector(1.0);
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

