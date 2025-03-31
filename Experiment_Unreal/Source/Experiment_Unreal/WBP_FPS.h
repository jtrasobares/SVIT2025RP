// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/ProgressBar.h"
#include "Blueprint/WidgetTree.h"
#include "WBP_FPS.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT_UNREAL_API UWBP_FPS : public UUserWidget
{
	GENERATED_BODY()

public:
    
   // UWBP_FPS(const FObjectInitializer& ObjectInitializer);
    // Referencia al Canvas Panel
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        UCanvasPanel* MyCanvasPanel;

    // Referencia al Progress Bar
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        UProgressBar* MyProgressBar;

};
