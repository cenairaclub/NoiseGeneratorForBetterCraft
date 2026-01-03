// Copyright 2026 UmutFaruk. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ThirdParty/Noisy/Public/Noisy.h"
#include "NoiseWrapper.generated.h"

// Renamed Enums for better clarity
UENUM(BlueprintType)
enum class ENoiseGeneratorType : uint8
{
	Value,
	ValueFractal,
	Perlin,
	PerlinFractal,
	Simplex,
	SimplexFractal,
	Cellular,
	WhiteNoise,
	Cubic,
	CubicFractal
};

UENUM(BlueprintType)
enum class ENoiseInterpolationMode : uint8
{
	Linear,
	Hermite,
	Quintic
};

UENUM(BlueprintType)
enum class ENoiseFractalType : uint8
{
	FBM,
	Billow,
	RigidMulti
};

UENUM(BlueprintType)
enum class ENoiseCellularDistanceMode : uint8
{
	Euclidean,
	Manhattan,
	Natural
};

UENUM(BlueprintType)
enum class ENoiseCellularReturnType : uint8
{
	CellValue,
	Distance,
	Distance2,
	Distance2Add,
	Distance2Sub,
	Distance2Mul,
	Distance2Div
};

// Configuration Struct to keep settings organized
USTRUCT(BlueprintType)
struct FNoiseGeneratorSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	int32 Seed = 1337;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	float Frequency = 0.01f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	ENoiseGeneratorType NoiseType = ENoiseGeneratorType::Simplex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	ENoiseInterpolationMode Interpolation = ENoiseInterpolationMode::Quintic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	ENoiseFractalType FractalType = ENoiseFractalType::FBM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	int32 Octaves = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	float Lacunarity = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	float Gain = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	float CellularJitter = 0.45f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	ENoiseCellularDistanceMode CellularDistanceFunction = ENoiseCellularDistanceMode::Euclidean;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Noise Settings")
	ENoiseCellularReturnType CellularReturnType = ENoiseCellularReturnType::CellValue;
};

UCLASS(BlueprintType, Blueprintable)
class NOISEGENERATOR_API UNoiseWrapper : public UObject
{
	GENERATED_BODY()
	
public:
	// -- Initialization --

	/** Configures the noise generator with the provided settings struct. */
	UFUNCTION(BlueprintCallable, Category = "Noise Generator")
	void ConfigureGenerator(const FNoiseGeneratorSettings& InSettings);

	/** Returns true if the generator has been configured at least once. */
	UFUNCTION(BlueprintPure, Category = "Noise Generator")
	bool IsInitialized() const { return bIsInitialized; }

	// -- Sampling --

	/** Sample 2D Noise at the given coordinates */
	UFUNCTION(BlueprintPure, Category = "Noise Generator")
	float SampleNoise2D(const float X, const float Y) const;

	/** Sample 3D Noise at the given coordinates */
	UFUNCTION(BlueprintPure, Category = "Noise Generator")
	float SampleNoise3D(const float X, const float Y, const float Z) const;

	// -- Dynamic Setters --

	UFUNCTION(BlueprintCallable, Category = "Noise Generator|Settings")
	void SetNoiseType(const ENoiseGeneratorType NewType);

	UFUNCTION(BlueprintCallable, Category = "Noise Generator|Settings")
	void SetInterpolation(const ENoiseInterpolationMode NewInterp);

	UFUNCTION(BlueprintCallable, Category = "Noise Generator|Settings")
	void SetFractalType(const ENoiseFractalType NewFractalType);

	UFUNCTION(BlueprintCallable, Category = "Noise Generator|Settings")
	void SetCellularDistanceFunction(const ENoiseCellularDistanceMode NewDistanceFunc);

	UFUNCTION(BlueprintCallable, Category = "Noise Generator|Settings")
	void SetCellularReturnType(const ENoiseCellularReturnType NewReturnType);

private:
	bool bIsInitialized = false;
	Noisy NativeFastNoise;
};
