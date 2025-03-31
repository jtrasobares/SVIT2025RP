// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Exercise_01.h"


//Define begin play
void AGM_Exercise_01::Init()
{

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);


	if (PlayerCharacter)
	{

		UInventoryManager* InventoryManager = NewObject<UInventoryManager>(PlayerCharacter);
		PlayerCharacter->AddOwnedComponent(InventoryManager);

		
		InventoryManager->FillAllItems();
	}
}


/*
void AGM_Exercise_01::ShowInfoItemWithDelay(WBP_Inventory* InventoryWidget)
{
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (PlayerCharacter)
	{
		UInventoryManager* InventoryManager = PlayerCharacter->FindComponentByClass<UInventoryManager>();
		//return the keys of the map

        TArray<FName> Keys;
        if (InventoryManager)
        {
            for (const auto& Pair : InventoryManager->Inventory)
            {
                Keys.Add(Pair.Key);
            }
        }
		//For each key, show the info of the item
		for (FName Key : Keys)
		{
			//Create a new FDataItem
			FDataItem Item;
			FTimerHandle TimerHandle;
			//use a interface to show the info of the item in user widget

			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [InventoryManager]()
				{
					// Continue with the rest of the code
				}, 2.0f, false);
			InventoryManager->FindItemByID(Key, Item);
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		
		}	
		
	}
}
*/
