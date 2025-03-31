// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/StructItem.h"
#include "Components/ActorComponent.h"
#include "InventoryManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENT_UNREAL_API UInventoryManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryManager();

	// Inventory is a map with string as key and FDataItem as value
	// property
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TMap<FName, FDataItem> Inventory;

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Functions to control the inventory, add, remove, find
	// Add item to the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItemToInventory(FName ID);

	// Remove item from the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItemByID(FName ID);
	
	// Find item in the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool FindItemByID(FName ID, FDataItem& ItemData);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void FillAllItems();
};
