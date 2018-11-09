// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControllerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s"), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank %s"), *PlayerTank->GetName());
	}
	
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerTank);
	}
}


ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


