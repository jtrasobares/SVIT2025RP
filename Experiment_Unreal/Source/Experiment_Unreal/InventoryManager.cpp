// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"

// Sets default values for this component's properties
UInventoryManager::UInventoryManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
//void UInventoryManager::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}


// Called every frame
//void UInventoryManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}
void UInventoryManager::AddItemToInventory(FName ID)
{
    
        // Get Data Table Row Item
        UDataTable* DataTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/Exercise1/Code/C_DTItems.C_DTItems'"));
        if (DataTable)
        {
            FDataItem* ItemData = DataTable->FindRow<FDataItem>(ID, TEXT(""));
            if (ItemData)
            {
                // Add item to inventory map
                Inventory.Add(ID, *ItemData);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Item with ID %s not found in data table"), *ID.ToString());
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to load data table"));
        }
   
}
void UInventoryManager::RemoveItemByID(FName ID)
{
    Inventory.Remove(ID);

}

bool UInventoryManager::FindItemByID(FName ID, FDataItem& ItemData)
{
    //TO DO
	return false;
}

void UInventoryManager::FillAllItems() {
    // Get Data Table Row Item
    UDataTable* DataTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/Exercise1/Code/C_DTItems.C_DTItems'"));

    if (DataTable)
	{
		TArray<FName> RowNames = DataTable->GetRowNames();
		for (FName rowName : RowNames)
		{
			AddItemToInventory(rowName);
			//log rowName
			UE_LOG(LogTemp, Warning, TEXT("Row Name: %s"), *rowName.ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load data table"));
	}

}
