// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	
	Super::BeginPlay();


	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("%s is not possesing a tank"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT(" %s is possesing %s"), *GetName(), *ControlledTank->GetName());
}
ATank* ATankPlayerController::GetControlledTank() const{

	return Cast<ATank>(GetPawn());
}


