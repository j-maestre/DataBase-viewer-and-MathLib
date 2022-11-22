#include <math.h>

namespace oxml {

  inline float Mathf::Abs(float value) {
    if (value < 0) {
      value *= -1.0;
    }
    return value;
  }

  inline bool Mathf::Approximately(float a, float b, float tolerance) {
    return (Abs(a - b) < tolerance);
  }

  inline float Mathf::Clamp(float value, float max, float min) {
    if (value > max) {
      value = max;
    }
    if (value < min) {
      value = min;
    }
    return value;
  }

  inline float Mathf::Clamp01(float value) {
    if (value > 1.0f) {
      value = 1.0f;
    }
    if (value < 0.0f) {
      value = 0.0f;
    }
    return value;
  }

  inline float Mathf::Pow(float value, float p) {
    return powf(value, p);
  }

  inline float Mathf::FloatModule(float a, float b) {
    return fmodf(a, b);
  }

  inline float Mathf::Round(float value) {
    return roundf(value);
  }

}