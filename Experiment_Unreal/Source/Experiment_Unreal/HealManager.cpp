// Fill out your copyright notice in the Description page of Project Settings.


#include "HealManager.h"

// Sets default values for this component's properties
UHealManager::UHealManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealManager::ConvertHealthToPercent(double& Percent)
{
	Percent = CurrentHealth / MaxHeal;
	
}
void UHealManager::UpdateHealth(float Damage)
{
	
	// Bloque de código a medir
	CurrentHealth -= Damage;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHeal);
}
void UHealManager::Init() {
	CurrentHealth = InitLife;
	UE_LOG(LogTemp, Warning, TEXT("Current life: %f "), CurrentHealth);
}

