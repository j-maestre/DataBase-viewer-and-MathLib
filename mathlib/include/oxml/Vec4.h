#ifndef __VEC4_H__
#define __VEC4_H__ 1

#include <oxml/Vec3.h>
#include <oxml/Mat3.h>

namespace oxml {

  class Vec4 {
   public:

    Vec4();
    Vec4(float x, float y, float z, float w);
    Vec4(Vec3 a, float w);
    Vec4(float a);
    Vec4(float* values_array);
    Vec4(const Vec4& other);
    ~Vec4();
    
    Vec4 operator+(const Vec4& other) const;
    Vec4 operator+(float value) const;
    void operator+=(const Vec4& other);
    void operator+=(float value);
    Vec4 operator-(const Vec4& other) const;
    Vec4 operator-(float value) const;
    void operator -=(const Vec4& other);
    void operator -=(float value);

    Vec4 operator*(float value) const;
    void operator*=(float value);
    Vec4 operator/(float value) const;
    void operator/=(float value);
    bool operator==(const Vec4& other);
    bool operator!=(const Vec4& other);
    void operator=(const Vec4& other);

    float Magnitude() const;
    void Normalize();
    Vec4 Normalized() const;
    void Scale(Vec4 scale);
    float SqrMagnitude() const;

    static float Distance(const Vec4& a, const Vec4& b);
    static float DotProduct(Vec4 a, Vec4 b);
    static Vec4 Lerp(const Vec4& a, const Vec4& b, float index);	

    static const Vec4 one;
    static const Vec4 zero;

    float x;
    float y;
    float z;
    float w;

  };


  inline float Vec4::Magnitude() const{
    return 0.0f;
  }

  inline void Vec4::Normalize() {	
  }

  inline Vec4 Vec4::Normalized() const {
    return Vec4();
  }

  inline void Vec4::Scale(Vec4 scale) {	
  }

  inline float Vec4::SqrMagnitude() const {
    return 0.0f;
  }

  inline float Vec4::Distance(const Vec4& a, const Vec4& b) {
    return 0.0f;
  }

  inline float Vec4::DotProduct(Vec4 a, Vec4 b) {
    return 0.0f;
  }

  inline Vec4 Vec4::Lerp(const Vec4& a, const Vec4& b, float index) {	
    return Vec4();
  }

  inline Vec4 Vec4::operator+(const Vec4& other) const{
    return Vec4();
  }

  inline Vec4 Vec4::operator+(float value) const{
    return Vec4();
  }

  inline void Vec4::operator+=(const Vec4& other) {

  }

  inline void Vec4::operator+=(float value) {
    
  }

  inline Vec4 Vec4::operator-(const Vec4& other) const{
    return Vec4();
  }

  inline Vec4 Vec4::operator-(float value) const{
    return Vec4();
  }

  inline void Vec4::operator -=(const Vec4& other) {	

  }

  inline void Vec4::operator -=(float value) {

  }

  inline Vec4 Vec4::operator*(float value) const{
    return Vec4();
  }

  inline void Vec4::operator*=(float value) {
  }

  inline Vec4 Vec4::operator/(float value) const{
    return Vec4();
  }

  inline void Vec4::operator/=(float value) {
  }

  inline bool Vec4::operator==(const Vec4& other) {
    return true;
  }

  inline bool Vec4::operator!=(const Vec4& other) {
    return true;
  }

  inline void Vec4::operator=(const Vec4& other) {
  }

}

#endif 
