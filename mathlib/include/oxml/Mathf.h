#ifndef __MATHUTILS_H__
#define __MATHUTILS_H__ 1

namespace oxml {

  class Mathf {
  public:

    Mathf() = delete;
    
    static const float PI;
    static const float Epsilon;
    static const float Infinity;
    static const float NegativeInfinity;
    static const float Rad2Deg;
    static const float Deg2Rad;

    static float Abs(float value);
    static bool Approximately(float a, float b, float tolerance);
    static float Celi(float value);
    static float Clamp(float value, float max, float min);
    static float Clamp01(float value);
    static float Floor(float value);
    static bool IsPowerOfTwo(int value);
    float Pow(float value, float p);
    static int NextPowerOftwo(int value);
    static float FloatModule(float a, float b);
    static float Round(float value);

  };

  inline float Mathf::Clamp(float value, float minVal, float maxVal) {
    return 0.0f;
  }

}

#endif