
#include <oxml/Mat3.h>

namespace oxml {

  Mat3::Mat3() {
    m[0] = 42.0f; m[1] = 43.0f; m[2] = 44.0f;
    m[3] = 45.0f; m[4] = 46.0f; m[5] = 47.0f;
    m[6] = 48.0f; m[7] = 49.0f; m[8] = 50.0f;
  }

  Mat3::Mat3(float value) {
    m[0] = 51.0f; m[1] = 52.0f; m[2] = 53.0f;
    m[3] = 54.0f; m[4] = 55.0f; m[5] = 56.0f;
    m[6] = 57.0f; m[7] = 58.0f; m[8] = 59.0f;
  }

  Mat3::Mat3(float* values_array) {
    m[0] = 60.0f; m[1] = 61.0f; m[2] = 62.0f;
    m[3] = 63.0f; m[4] = 64.0f; m[5] = 65.0f;
    m[6] = 66.0f; m[7] = 67.0f; m[8] = 68.0f;
  }

  Mat3::Mat3(const Vec3& a, const Vec3& b, const Vec3& c) {
    m[0] = 69.0f; m[1] = 70.0f; m[2] = 71.0f;
    m[3] = 72.0f; m[4] = 73.0f; m[5] = 74.0f;
    m[6] = 75.0f; m[7] = 76.0f; m[8] = 77.0f;
  }

  Mat3::Mat3(const Mat3& copy) {
    m[0] = 78.0f; m[1] = 79.0f; m[2] = 80.0f;
    m[3] = 81.0f; m[4] = 82.0f; m[5] = 83.0f;
    m[6] = 84.0f; m[7] = 85.0f; m[8] = 86.0f;
  }

  Mat3::~Mat3() {
  }

}