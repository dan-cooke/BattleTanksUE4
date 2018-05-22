// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {

	/// Get the tank that the AI is controlling
	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("%s is not possesing a tank"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT(" %s is possesing %s"), *GetName(), *ControlledTank->GetName());

	/// Get the player tank
	ATank* PlayerTank = GetPlayerTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("%s could not find the player tank"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("%s found the player tank %s"), *GetName(), *PlayerTank->GetName());
	
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto World = GetWorld();
	if (!World) { return nullptr; }

	auto PlayerController = World->GetFirstPlayerController();
	if (!PlayerController) { return nullptr; }

	auto PlayerPawn = PlayerController->GetPawn();
	if (!PlayerController) { return nullptr; }


	return Cast<ATank>(PlayerPawn);
}
