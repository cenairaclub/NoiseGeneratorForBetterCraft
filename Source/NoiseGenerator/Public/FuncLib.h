// Copyright 2026 UmutFaruk. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FuncLib.generated.h"

/**
 * 
 */
UCLASS()
class NOISEGENERATOR_API UFuncLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/**
	 * Deletes a directory and all of its contents recursively.
	 * @param DirectoryPath Absolute or relative path
	 * @return true if deletion succeeded
	 */
	UFUNCTION(BlueprintCallable, Category = "File System")
	static bool DeleteDirectory(const FString& DirectoryPath);

	/**
	 * Checks if a directory exists
	 */
	UFUNCTION(BlueprintPure, Category = "File System")
	static bool DoesDirectoryExist(const FString& DirectoryPath);
};
