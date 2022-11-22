namespace oxml {

  inline float Mathf::Abs(float value) {
    if (value < 0) {
      value *= -1.0;
    }
    return value;
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

}