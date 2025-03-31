// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPS_HUD.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT_UNREAL_API AFPS_HUD : public AHUD
{
	GENERATED_BODY()

/** Please add a variable description */
UPROPERTY(VisibleAnywhere, Category = "Default")
TObjectPtr<USceneComponent> DefaultSceneRoot;




};
