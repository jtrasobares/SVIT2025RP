// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Exercise_03.h"


void AGM_Exercise_03::Init()
{

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	
	if (PlayerCharacter)
	{
		
		UHealManager* HealManager = NewObject<UHealManager>(PlayerCharacter);
		PlayerCharacter->AddOwnedComponent(HealManager);

		// Llamar a la funci�n Init del HealManager
		HealManager->Init();
	}
}