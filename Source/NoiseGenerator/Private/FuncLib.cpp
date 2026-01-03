// Copyright 2026 UmutFaruk. All rights reserved.


#include "FuncLib.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
bool UFuncLib::DeleteDirectory(const FString& DirectoryPath)
{
	if (DirectoryPath.IsEmpty())
	{
		return false;
	}

	FString NormalizedPath = DirectoryPath;
	FPaths::NormalizeDirectoryName(NormalizedPath);

	if (!IFileManager::Get().DirectoryExists(*NormalizedPath))
	{
		return false;
	}

	return IFileManager::Get().DeleteDirectory(
		*NormalizedPath,
		/*RequireExists*/ false,
		/*Tree*/ true
	);
}

bool UFuncLib::DoesDirectoryExist(const FString& DirectoryPath)
{
	if (DirectoryPath.IsEmpty())
	{
		return false;
	}

	FString NormalizedPath = DirectoryPath;
	FPaths::NormalizeDirectoryName(NormalizedPath);

	return IFileManager::Get().DirectoryExists(*NormalizedPath);
}