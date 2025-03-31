// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "InputCore.h"
#include "customPlayer.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class EXPERIMENT_UNREAL_API AcustomPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AcustomPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Create camera component, and spring arm component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* Camera;



	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
		UInputMappingContext* InputMapping;
	//input actions for move, look and jump
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
		UInputAction* IA_Move;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
		UInputAction* IA_Look;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
		UInputAction* IA_Jump;
	//Functions for input actions FInputActionValue
	UFUNCTION()
		void OnMove(const FInputActionValue& Value);
	UFUNCTION()
		void OnLook(const FInputActionValue& Value);
	UFUNCTION()
		void OnJump(const FInputActionValue& Value);
};
