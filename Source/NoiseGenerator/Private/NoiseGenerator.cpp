// Copyright 2026 UmutFaruk. All rights reserved.

#include "NoiseGenerator.h"

#define LOCTEXT_NAMESPACE "FNoiseGeneratorModule"

void FNoiseGeneratorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FNoiseGeneratorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNoiseGeneratorModule, NoiseGenerator)