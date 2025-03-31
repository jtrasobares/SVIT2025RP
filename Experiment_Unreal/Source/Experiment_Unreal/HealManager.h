// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENT_UNREAL_API UHealManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Please add a function description */
	UFUNCTION(BlueprintPure)
		void ConvertHealthToPercent(double& Percent);
	UFUNCTION(BlueprintCallable, Category = "Health")
		void UpdateHealth(float Damage);
	UFUNCTION(BlueprintCallable, Category = "Health")
		void Init();

	// Declaraci�n e inicializaci�n de las variables con UPROPERTY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float CurrentHealth = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float InitLife = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHeal = 100.0f;


};
