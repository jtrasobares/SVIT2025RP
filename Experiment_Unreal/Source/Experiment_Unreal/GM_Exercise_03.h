// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HealManager.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GM_Exercise_03.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT_UNREAL_API AGM_Exercise_03 : public AGameModeBase
{
	GENERATED_BODY()
	
		
public :

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Init();

};
