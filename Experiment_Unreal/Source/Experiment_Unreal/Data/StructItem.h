// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "StructItem.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
//Enum for item type
enum class EItemType : uint8
{
	IT_Consumable UMETA(DisplayName = "Consumable"),
	IT_Weapon UMETA(DisplayName = "Weapon"),
	IT_Armor UMETA(DisplayName = "Armor"),
	IT_Ammo UMETA(DisplayName = "Ammo"),
	IT_Misc UMETA(DisplayName = "Misc")
};

USTRUCT(BlueprintType)
struct FDataItem : public FTableRowBase
{
    GENERATED_BODY()
public:

       //ID for the item Name
	   UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	   FName ID;
	   
    //Create properties for Item struct
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
FString Description;
    //icon texture 2d
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
		UTexture2D* Icon;
	//item type its a enum default is consumable
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
		EItemType ItemType = EItemType::IT_Consumable;

       
};