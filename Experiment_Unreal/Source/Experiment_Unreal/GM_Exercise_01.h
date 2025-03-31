// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryManager.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GM_Exercise_01.generated.h"

UCLASS()
class EXPERIMENT_UNREAL_API AGM_Exercise_01 : public AGameModeBase
{
	GENERATED_BODY()
	//game play
public:
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void Init();
	

   // UFUNCTION(BlueprintCallable, Category = "Gameplay")

   // void ShowInfoItemWithDelay(WBP_Inventory* InventoryWidget);
};
