# Noise Generator Plugin

[README - TÜRKÇE - TURKISH <<<--](https://github.com/cenairaclub/NoiseGeneratorForBetterCraft/blob/main/README_Turkish.md)

**Noise Generator** is a fast and flexible noise generation plugin for Unreal Engine, suitable for procedural content generation, terrain shaping, and various effects.

This plugin provides the `UNoiseWrapper` class, allowing you to easily use popular noise algorithms (Perlin, Simplex, Cellular, etc.) via both Blueprint and C++.

## Features

*   **Various Noise Types:** Perlin, Simplex, Value, Cellular, White Noise, Cubic, and their Fractal variations.
*   **Full Blueprint Support:** All settings and functions are accessible via Blueprint.
*   **Easy Configuration:** Dynamic setting changes individually or in bulk using the `FNoiseGeneratorSettings` structure.
*   **2D and 3D Sampling:** Get 2D or 3D noise values based on your needs.

## Installation

1.  **Download:** Download the plugin files.
2.  **Copy:** Copy the `NoiseGenerator` folder into the `Plugins` directory in your project's root folder (create the directory if it doesn't exist).
    *   Path should look like: `[ProjectFolder]/Plugins/NoiseGenerator/`
3.  **Open Project:** Open Unreal Editor. It may detect the new plugin and ask if you want to compile. Click "Yes" to proceed.
4.  **Enable:** Go to `Edit > Plugins` and ensure the "Noise Generator" plugin is enabled.

## Usage

### Blueprint Usage

1.  **Create Object:**
    In any Blueprint (e.g., an Actor or GameMode), use the `Construct Object from Class` node and select `Noise Wrapper` as the Class. Promote the return value to a variable.

2.  **Configuration (Optional but Recommended):**
    Call the `Configure Generator` function on your created `Noise Wrapper` object.
    *   **Seed:** Randomness seed (same seed always produces the same result).
    *   **Frequency:** Frequency/scale of the noise.
    *   **Noise Type:** Algorithm to use (e.g., `Simplex`, `Perlin`).
    *   **Fractal Type, Octaves, etc.:** Detail level settings.

3.  **Sample Noise:**
    Call `Sample Noise 2D` or `Sample Noise 3D` to get a float value (usually between -1.0 and 1.0).
    *   Input X, Y (and Z) coordinates. These are typically World Location or UV coordinates.

**Example Flow:**
`BeginPlay` -> `Construct Object (NoiseWrapper)` -> `Configure Generator` -> `Create Settings Variable`
In Loop -> `Sample Noise 2D (X, Y)` -> Use the result (e.g., as Z height).

### C++ Usage

Add the `NoiseGenerator` module to your project's `Build.cs` file:

```csharp
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NoiseGenerator" });
```

Include the header in the class you wish to use it:

```cpp
#include "NoiseWrapper.h"
```

Create the object and use it:

```cpp
void AMyActor::StartNoiseGeneration()
{
    // Create a new NoiseWrapper object
    UNoiseWrapper* NoiseGen = NewObject<UNoiseWrapper>(this);

    // Prepare settings
    FNoiseGeneratorSettings Settings;
    Settings.Seed = 12345;
    Settings.Frequency = 0.02f;
    Settings.NoiseType = ENoiseGeneratorType::PerlinFractal;
    Settings.Octaves = 4;

    // Configure the generator
    NoiseGen->ConfigureGenerator(Settings);

    // Sample a value
    float MyNoiseValue = NoiseGen->SampleNoise2D(100.0f, 200.0f);
    
    UE_LOG(LogTemp, Log, TEXT("Noise Value: %f"), MyNoiseValue);
}
```

## Settings (FNoiseGeneratorSettings)

| Setting | Description |
| :--- | :--- |
| **Seed** | Base number used for noise generation. Same seed produces the same output. |
| **Frequency** | Frequency of the noise. Low values create broader, smoother changes; high values create more frequent changes. |
| **Noise Type** | Algorithm type (Simplex, Perlin, Cellular, etc.). |
| **Interpolation** | Smoothness of transition between points (Linear, Hermite, Quintic). |
| **Fractal Type** | Fractal noise method (Brownian Motion, Billow, etc.). |
| **Octaves** | Number of fractal layers. Higher values mean more detail but more processing cost. |
| **Lacunarity** | Frequency multiplier per octave. |
| **Gain** | Amplitude reduction per octave. |
| **Cellular Jitter** | Irregularity of points in cellular noise. |

## License

This plugin is open source and distributed under the MIT license.
