# Noise Generator Plugin

**Noise Generator**, Unreal Engine projelerinizde prosedürel içerik oluşturma, arazi (terrain) şekillendirme ve çeşitli efektler için kullanabileceğiniz hızlı ve esnek bir gürültü (noise) oluşturma eklentisidir.

Bu eklenti, popüler gürültü algoritmalarını (Perlin, Simplex, Cellular, vb.) Blueprint ve C++ üzerinden kolayca kullanmanızı sağlayan `UNoiseWrapper` sınıfını sunar.

## Özellikler

*   **Çeşitli Noise Tipleri:** Perlin, Simplex, Value, Cellular, White Noise, Cubic ve bunların Fractal varyasyonları.
*   **Tam Blueprint Desteği:** Tüm ayarlar ve fonksiyonlar Blueprint üzerinden erişilebilir.
*   **Kolay Yapılandırma:** `FNoiseGeneratorSettings` yapısı ile toptan veya tek tek fonksiyonlar ile dinamik ayar değişimi.
*   **2D ve 3D Örnekleme:** İhtiyacınıza göre 2 veya 3 boyutlu gürültü değerleri alabilirsiniz.

## Kurulum

1.  **İndirin:** Eklenti dosyalarını indirin.
2.  **Kopyalayın:** Projenizin ana dizinindeki `Plugins` klasörüne (yoksa oluşturun) `NoiseGenerator` klasörünü kopyalayın.
    *   Yol şöyle olmalı: `[ProjeKlasörü]/Plugins/NoiseGenerator/`
3.  **Projenizi Açın:** Unreal Editor'ü açın. Yeni eklentiyi algılayacak ve derlemek isteyip istemediğinizi sorabilir. "Yes" diyerek ilerleyin.
4.  **Aktifleştirin:** `Edit > Plugins` menüsünden "Noise Generator" eklentisinin "Enabled" olduğundan emin olun.

## Kullanım

### Blueprint ile Kullanım

1.  **Objeyi Oluşturun:**
    Herhangi bir Blueprint içinde (örneğin bir Actor veya GameMode), `Construct Object from Class` düğmesini kullanın ve Class olarak `Noise Wrapper` seçin. Dönüş değerini bir değişkene atayın (Promote to Variable).

2.  **Yapılandırma (Opsiyonel ama Önerilen):**
    Oluşturduğunuz `Noise Wrapper` objesi üzerinden `Configure Generator` fonksiyonunu çağırın.
    *   **Seed:** Rastgelelik tohumu (aynı seed her zaman aynı sonucu verir).
    *   **Frequency:** Gürültünün sıklığı/ölçeği.
    *   **Noise Type:** Kullanılacak algoritma (örn. `Simplex`, `Perlin`).
    *   **Fractal Type, Octaves, vs.:** Detay seviyesi ayarları.

3.  **Noise Değeri Alma:**
    `Sample Noise 2D` veya `Sample Noise 3D` fonksiyonlarını çağırarak -1.0 ile 1.0 arasında (genellikle) bir float değer alabilirsiniz.
    *   Girdi olarak X, Y (ve Z) koordinatlarını verin. Bu koordinatlar genellikle dünya pozisyonu (World Location) veya UV koordinatlarıdır.

**Örnek Akış:**
`BeginPlay` -> `Construct Object (NoiseWrapper)` -> `Configure Generator` -> `Settings Değişkeni Oluştur`
Döngü içinde -> `Sample Noise 2D (X, Y)` -> Elde edilen değeri kullan (örn. Z yüksekliği olarak).

### C++ ile Kullanım

Projenizin `Build.cs` dosyasına `NoiseGenerator` modülünü ekleyin:

```csharp
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NoiseGenerator" });
```

Kullanmak istediğiniz sınıfta header'ı ekleyin:

```cpp
#include "NoiseWrapper.h"
```

Objeyi oluşturun ve kullanın:

```cpp
void AMyActor::StartNoiseGeneration()
{
    // Yeni bir NoiseWrapper objesi oluştur
    UNoiseWrapper* NoiseGen = NewObject<UNoiseWrapper>(this);

    // Ayarları hazırla
    FNoiseGeneratorSettings Settings;
    Settings.Seed = 12345;
    Settings.Frequency = 0.02f;
    Settings.NoiseType = ENoiseGeneratorType::PerlinFractal;
    Settings.Octaves = 4;

    // Jeneratörü yapılandır
    NoiseGen->ConfigureGenerator(Settings);

    // Bir değer örnekle
    float MyNoiseValue = NoiseGen->SampleNoise2D(100.0f, 200.0f);
    
    UE_LOG(LogTemp, Log, TEXT("Noise Değeri: %f"), MyNoiseValue);
}
```

## Ayarlar (FNoiseGeneratorSettings)

| Ayar | Açıklama |
| :--- | :--- |
| **Seed** | Gürültü üretimi için kullanılan temel sayı. Aynı seed aynı çıktıyı üretir. |
| **Frequency** | Gürültünün sıklığı. Düşük değerler daha geniş, yumuşak değişimler; yüksek değerler daha sık değişimler yaratır. |
| **Noise Type** | Algoritma türü (Simplex, Perlin, Cellular, vb.). |
| **Interpolation** | Noktalar arası geçiş yumuşaklığı (Linear, Hermite, Quintic). |
| **Fractal Type** | Fraktal gürültü yöntemi (Brownian Motion, Billow, vb.). |
| **Octaves** | Fraktal katman sayısı. Yüksek değerler daha fazla detay ama daha fazla işlem gücü demektir. |
| **Lacunarity** | Her oktavda frekansın ne kadar artacağı. |
| **Gain** | Her oktavda etkinin (amplitude) ne kadar azalacağı. |
| **Cellular Jitter** | Hücresel gürültüde noktaların düzensizliği. |

## Lisans

Bu eklenti açık kaynaklıdır ve MIT lisansı altında dağıtılmaktadır. (Burayı projenizin lisansına göre düzenleyebilirsiniz)
