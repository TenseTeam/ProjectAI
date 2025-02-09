// Copyright The Prototypers, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Gameplay/InventorySystem/UObjects/ItemBase.h"
#include "ItemData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class PROJECTAI_API UItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory System|Item")
	TSubclassOf<UItemBase> ItemClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory System|Item")
	FString ItemName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory System|Item", meta=(MultiLine="true"))
	FText ItemDescription;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory System|Item")
	FSlateBrush ItemIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory System|Item", meta=(ClampMin="1", UIMin="1"))
	int32 MaxStackSize = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory System|Item")
	bool bIsUnique;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory System|Item")
	bool bIsConsumable;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory System|Item")
	UObject* Metadata;

	FORCEINLINE FName GetItemID() const
	{
		const int32 Hash = GetTypeHash(GetFName()) + GetTypeHash(ItemName);
		const FString Hex = FString::Printf(TEXT("%08X"), Hash);
		return FName(*Hex);
	}
};
