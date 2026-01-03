// Copyright 2026 UmutFaruk. All rights reserved.

#include "NoiseWrapper.h"

void UNoiseWrapper::ConfigureGenerator(const FNoiseGeneratorSettings& InSettings)
{
	NativeFastNoise.SetSeed(InSettings.Seed);
	NativeFastNoise.SetFrequency(InSettings.Frequency);
	NativeFastNoise.SetFractalOctaves(InSettings.Octaves);
	NativeFastNoise.SetFractalLacunarity(InSettings.Lacunarity);
	NativeFastNoise.SetFractalGain(InSettings.Gain);
	NativeFastNoise.SetCellularJitter(InSettings.CellularJitter);

	SetNoiseType(InSettings.NoiseType);
	SetInterpolation(InSettings.Interpolation);
	SetFractalType(InSettings.FractalType);
	SetCellularDistanceFunction(InSettings.CellularDistanceFunction);
	SetCellularReturnType(InSettings.CellularReturnType);

	bIsInitialized = true;
}

float UNoiseWrapper::SampleNoise2D(const float X, const float Y) const
{
	return IsInitialized() ? NativeFastNoise.GetNoise(X, Y) : 0.0f;
}

float UNoiseWrapper::SampleNoise3D(const float X, const float Y, const float Z) const
{
	return IsInitialized() ? NativeFastNoise.GetNoise(X, Y, Z) : 0.0f;
}

void UNoiseWrapper::SetNoiseType(const ENoiseGeneratorType NewType)
{
	switch (NewType)
	{
	case ENoiseGeneratorType::Value:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::Value);
		break;
	case ENoiseGeneratorType::ValueFractal:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::ValueFractal);
		break;
	case ENoiseGeneratorType::Perlin:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::Perlin);
		break;
	case ENoiseGeneratorType::PerlinFractal:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::PerlinFractal);
		break;
	case ENoiseGeneratorType::Simplex:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::Simplex);
		break;
	case ENoiseGeneratorType::SimplexFractal:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::SimplexFractal);
		break;
	case ENoiseGeneratorType::Cellular:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::Cellular);
		break;
	case ENoiseGeneratorType::WhiteNoise:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::WhiteNoise);
		break;
	case ENoiseGeneratorType::Cubic:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::Cubic);
		break;
	case ENoiseGeneratorType::CubicFractal:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::CubicFractal);
		break;
	default:
		NativeFastNoise.SetNoiseType(Noisy::NoiseType::Simplex);
		break;
	}
}

void UNoiseWrapper::SetInterpolation(const ENoiseInterpolationMode NewInterp)
{
	switch (NewInterp)
	{
	case ENoiseInterpolationMode::Linear:
		NativeFastNoise.SetInterp(Noisy::Interp::Linear);
		break;
	case ENoiseInterpolationMode::Hermite:
		NativeFastNoise.SetInterp(Noisy::Interp::Hermite);
		break;
	case ENoiseInterpolationMode::Quintic:
		NativeFastNoise.SetInterp(Noisy::Interp::Quintic);
		break;
	default:
		NativeFastNoise.SetInterp(Noisy::Interp::Quintic);
		break;
	}
}

void UNoiseWrapper::SetFractalType(const ENoiseFractalType NewFractalType)
{
	switch (NewFractalType)
	{
	case ENoiseFractalType::FBM:
		NativeFastNoise.SetFractalType(Noisy::FractalType::FBM);
		break;
	case ENoiseFractalType::Billow:
		NativeFastNoise.SetFractalType(Noisy::FractalType::Billow);
		break;
	case ENoiseFractalType::RigidMulti:
		NativeFastNoise.SetFractalType(Noisy::FractalType::RigidMulti);
		break;
	default:
		NativeFastNoise.SetFractalType(Noisy::FractalType::FBM);
		break;
	}
}

void UNoiseWrapper::SetCellularDistanceFunction(const ENoiseCellularDistanceMode NewDistanceFunc)
{
	switch (NewDistanceFunc)
	{
	case ENoiseCellularDistanceMode::Euclidean:
		NativeFastNoise.SetCellularDistanceFunction(Noisy::CellularDistanceFunction::Euclidean);
		break;
	case ENoiseCellularDistanceMode::Manhattan:
		NativeFastNoise.SetCellularDistanceFunction(Noisy::CellularDistanceFunction::Manhattan);
		break;
	case ENoiseCellularDistanceMode::Natural:
		NativeFastNoise.SetCellularDistanceFunction(Noisy::CellularDistanceFunction::Natural);
		break;
	default:
		NativeFastNoise.SetCellularDistanceFunction(Noisy::CellularDistanceFunction::Euclidean);
		break;
	}
}

void UNoiseWrapper::SetCellularReturnType(const ENoiseCellularReturnType NewReturnType)
{
	switch (NewReturnType)
	{
	case ENoiseCellularReturnType::CellValue:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::CellValue);
		break;
	case ENoiseCellularReturnType::Distance:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::Distance);
		break;
	case ENoiseCellularReturnType::Distance2:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::Distance2);
		break;
	case ENoiseCellularReturnType::Distance2Add:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::Distance2Add);
		break;
	case ENoiseCellularReturnType::Distance2Sub:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::Distance2Sub);
		break;
	case ENoiseCellularReturnType::Distance2Mul:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::Distance2Mul);
		break;
	case ENoiseCellularReturnType::Distance2Div:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::Distance2Div);
		break;
	default:
		NativeFastNoise.SetCellularReturnType(Noisy::CellularReturnType::CellValue);
		break;
	}
}
