#include <math.h>

#include <oxml/assert.h>
#include <oxml/Mathf.h>

namespace oxml {

  inline Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(this->x + other.x, this->y + other.y);
  }

  inline Vec2 Vec2::operator+(float value) const{
    return Vec2(this->x + value, this->y + value);
  }

  inline Vec2& Vec2::operator+=(const Vec2& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  inline Vec2& Vec2::operator+=(float value) {
    this->x += value;
    this->y += value;
    return *this;
  }

  inline Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(this->x - other.x, this->y - other.y);
  }

  inline Vec2 Vec2::operator-(float value) const {
    return Vec2(this->x - value, this->y - value);
  }

  inline Vec2& Vec2::operator-() {
    return Vec2(this->x*(-1.0f),this->y*(-1.0f));
  }

  inline Vec2& Vec2::operator-=(const Vec2& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
  }

  inline Vec2& Vec2::operator-=(float value) {
    this->x -= value;
    this->y -= value;
    return *this;
  }

  inline bool Vec2::operator==(const Vec2& other) const {
    return (this->x == other.x && this->y == other.y);
  }

  inline bool Vec2::operator!=(const Vec2& other) const {
    return (this->x != other.x && this->y != other.y);
  }

  inline void Vec2::operator=(const Vec2& other) {
    this->x = other.x;
    this->y = other.y;
  }

  inline void Vec2::operator=(float value) {
    this->x = value;
    this->y = value;
  }

  inline Vec2 Vec2::operator*(float value) const {
    return Vec2(this->x * value, this->y * value);
  }

  inline Vec2& Vec2::operator*=(float value) {
    this->x *= value;
    this->y *= value;
    return *this;
  }

  inline Vec2 Vec2::operator/(float value) const {
    return Vec2(this->x / value, this->y / value);
  }

  inline Vec2& Vec2::operator/=(float value) {
    this->x /= value;
    this->y /= value;
    return *this;
  }

  inline float& Vec2::operator[](int index) {
    assert(index <= 1 && index > 0, "Index out of range");
    switch(index){
     case 0:
      return x;
     case 1:
      return y;
    }
  }

  inline const float& Vec2::operator[](int index) const {
    assert(index <= 1 && index > 0, "Index out of range");
    switch(index){
     case 0:
      return x;
     case 1:
      return y;
    }
  }

  inline float Vec2::Magnitude() const {
    return sqrtf((this->x * this->x) + (this->y * this->y));
  }

  inline void Vec2::Normalize() {
    float hipotenusa = sqrtf((this->x * this->x) + (this->y * this->y));
    this->x /= hipotenusa;
    this->y /= hipotenusa;
  }

  inline Vec2 Vec2::Normalized() const {
    float hipotenusa = sqrtf((this->x * this->x) + (this->y * this->y));
    return Vec2((float)this->x / hipotenusa, (float)this->y / hipotenusa);
  }

  inline void Vec2::Scale(const Vec2& scale) {
    this->x *= scale.x;
    this->y *= scale.y;
  }

  inline float Vec2::SqrMagnitude() const {
    return (this->x * this->x) + (this->y * this->y);
  }

  inline float Vec2::Distance(const Vec2& a, const Vec2& b) {
    return sqrtf(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
  }

  inline Vec2 Vec2::Lerp(const Vec2& a, const Vec2& b, float t) {
    t = Mathf::Clamp01(t);
    return Vec2(a + (b - a) * t);
  }

  inline Vec2 Vec2::LerpUnclamped(const Vec2& a, const Vec2& b, float t) {
    return Vec2(a + (b - a) * t);
  }

  inline float Vec2::Dot(const Vec2& a, const Vec2& b) {
    return (float)((a.x * b.x) + (a.y * b.y));
  }

  inline bool Approximately(const Vec2& a, const Vec2& b, float tolerance) {
    return Mathf::Abs(b.x - a.x) <= tolerance && Mathf::Abs(b.y - a.y) <= tolerance;
  }

}