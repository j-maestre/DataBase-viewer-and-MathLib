#include <oxml/assert.h>
#include <oxml/Mathf.h>

namespace oxml {

  inline float Vec4::Magnitude() const {
    return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
  }

  inline void Vec4::Normalize() {
    float magnitude = Magnitude();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    w /= magnitude;
  }

  inline Vec4 Vec4::Normalized() const {
    Vec4 rslt(*this);
    rslt.Normalize();
    return rslt;
  }

  inline void Vec4::Scale(const Vec4& scale) {
    x *= scale.x;
    y *= scale.y;
    z *= scale.z;
    w *= scale.w;
  }

  inline float Vec4::SqrMagnitude() const {
    return (x * x) + (y * y) + (z * z) + (w * w);
  }

  inline float Vec4::Distance(const Vec4& a, const Vec4& b) {
    return (a - b).Magnitude();
  }

  inline float Vec4::Dot(const Vec4& a, const Vec4& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
  }

  inline Vec4 Vec4::Lerp(const Vec4& a, const Vec4& b, float t) {
    t = Mathf::Clamp01(t);
    return Vec4(a + ((b - a) * t));
  }

  inline bool Vec4::Approximately(const Vec4& a, const Vec4& b, float tolerance) {
    return Mathf::Abs(b.x - a.x) <= tolerance && Mathf::Abs(b.y - a.y) <= tolerance && Mathf::Abs(b.z - a.z) <= tolerance && Mathf::Abs(b.w - a.w) <= tolerance;
  }

  inline Vec4 Vec4::operator+(const Vec4& other) const {
    return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
  }

  inline Vec4 Vec4::operator+(float value) const {
    return Vec4(x + value, y + value, z + value, w + value);
  }

  inline Vec4& Vec4::operator+=(const Vec4& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }

  inline Vec4& Vec4::operator+=(float value) {
    x += value;
    y += value;
    z += value;
    w += value;
    return *this;
  }

  inline Vec4 Vec4::operator-(const Vec4& other) const {
    return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  inline Vec4 Vec4::operator-(float value) const {
    return Vec4(x - value, y - value, z - value, w - value);
  }

  inline Vec4 Vec4::operator-() const {
    return Vec4(x * -1.0f, y * -1.0f, z * -1.0f, w * -1.0f);
  }

  inline Vec4& Vec4::operator -=(const Vec4& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }

  inline Vec4& Vec4::operator -=(float value) {
    x -= value;
    y -= value;
    z -= value;
    w -= value;
    return *this;
  }

  inline Vec4 Vec4::operator*(float value) const {
    return Vec4(x * value, y * value, z * value, w * value);
  }

  inline Vec4& Vec4::operator*=(float value) {
    x *= value;
    y *= value;
    z *= value;
    w *= value;
    return *this;
  }

  inline Vec4 Vec4::operator/(float value) const {
    return Vec4(x / value, y / value, z / value, w / value);
  }

  inline Vec4& Vec4::operator/=(float value) {
    x /= value;
    y /= value;
    z /= value;
    w /= value;
    return *this;
  }

  inline bool Vec4::operator==(const Vec4& other) {
    return (x == other.x && y == other.y && z == other.z && w == other.w);
  }

  inline bool Vec4::operator!=(const Vec4& other) {
    return (x != other.x && y != other.y && z != other.z && w != other.w);
  }

  inline Vec4& Vec4::operator=(const Vec4& other) {
    if (this != &other) {
      x = other.x;
      y = other.y;
      z = other.z;
      w = other.w;
    }
    return *this;
  }

  inline float& Vec4::operator[](int index) {
    assert(index <= 3 && index > 0, "Index out of range");
    switch (index) {
     default:
     case 0:
      return this->x;
     case 1:
      return this->y;
     case 2:
      return this->z;
     case 3:
      return this->w;
    }
  }

  inline const float& Vec4::operator[](int index) const {
    assert(index <= 3 && index > 0, "Index out of range");
    switch (index) {
    default:
    case 0:
      return this->x;
    case 1:
      return this->y;
    case 2:
      return this->z;
    case 3:
      return this->w;
    }
  }

}