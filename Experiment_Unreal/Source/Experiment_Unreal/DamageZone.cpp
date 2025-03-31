// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageZone.h"

// Sets default values
ADamageZone::ADamageZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	BoxCollision->SetGenerateOverlapEvents(true);
	RootComponent = BoxCollision;
	BoxCollision->InitBoxExtent(FVector(200.0f, 200.0f, 50.0f));

	

	Fire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire"));
	Fire->SetupAttachment(BoxCollision);
	Fire->bAutoActivate = true;
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FireTemplate(TEXT("/Game/Exercise3/Base/Particles/P_Fire.P_Fire"));
	if (FireTemplate.Succeeded())
	{
		Fire->SetTemplate(FireTemplate.Object);
	}
}

// Called when the game starts or when spawned
void ADamageZone::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ADamageZone::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ADamageZone::OnOverlapEnd);
}

// Called every frame
void ADamageZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADamageZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TO DO
}

void ADamageZone::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//TO DO
}

void ADamageZone::StartDamageLoop()
{
	//TO DO
		
}
// Handles periodic damage application
void ADamageZone::DamageFire()
{
	//TO DO
}

// Stops the damage loop
void ADamageZone::StopDamageLoop()
{
	//TO DO
}
