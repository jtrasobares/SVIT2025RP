// Fill out your copyright notice in the Description page of Project Settings.


#include "customPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Input/Events.h"
#include "Components/InputComponent.h"

// Sets default values
AcustomPlayer::AcustomPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//create sprint arm and camera
SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
SpringArm->SetupAttachment(RootComponent);
	
SpringArm->TargetArmLength = 300.0f;
SpringArm->bUsePawnControlRotation = true;

Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
Camera->SetupAttachment(SpringArm);
//rotate pawn to face the camera
Camera->bUsePawnControlRotation = false;
GetCharacterMovement()->bOrientRotationToMovement = true;

//location mesh 0,0,-90 rotation 0,0,-90
GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
GetMesh()->SetRelativeRotation(FRotator(0.0f,270.0f, 0.0f));

}

// Called when the game starts or when spawned
void AcustomPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
//void AcustomPlayer::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	
//
//
//	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
//
//	if (PlayerController)
//	{
//		//PlayerController->InputKey(EKeys::SpaceBar, EInputEvent::IE_Pressed, 1, false);
//	
////use control rotation to move the player
//
//		float AmountDepressed = FMath::RandRange(0.0f, 1.0f);
//
//		// Choose a random movement direction (forward, left, or right)
//		int RandomDirection = FMath::RandRange(0, 2);
//
//		switch (RandomDirection) {
//		case 0:  // Forward
//			PlayerController->InputKey(EKeys::W, EInputEvent::IE_Pressed, 1, false);
//			break;
//		case 1:  // Left
//			PlayerController->InputKey(EKeys::A, EInputEvent::IE_Pressed, 1, false);
//			break;
//		case 2:  // Right
//			PlayerController->InputKey(EKeys::D, EInputEvent::IE_Pressed, 1, false);
//			break;
//		}
//
//	}
//
//}

// Called to bind functionality to input
void AcustomPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
	//Binds input action to functions
	UEnhancedInputComponent* InputMove = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	InputMove->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AcustomPlayer::OnMove);

	//make UEnhancedInputComponent to look and jump
	UEnhancedInputComponent* InputLook = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	InputLook->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AcustomPlayer::OnLook);

	UEnhancedInputComponent* InputJump = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	InputJump->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AcustomPlayer::OnJump);

}

void AcustomPlayer::OnMove(const FInputActionValue& Value)
{
	//TO DO
}

void AcustomPlayer::OnLook(const FInputActionValue& Value)
{
	FVector2D Axis2DValue = Value.Get<FVector2D>();
	//look around with the camera with Fvector2d
	AddControllerYawInput(Axis2DValue.X);
	AddControllerPitchInput(Axis2DValue.Y);

}

void AcustomPlayer::OnJump(const FInputActionValue& Value)
{
	bool BoolValue = Value.Get<bool>(); // for digital input actions
if (BoolValue)
	{
		Jump();
	}
	else
	{
		StopJumping();
	}

}

