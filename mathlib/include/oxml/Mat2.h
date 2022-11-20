//--------------------------------------------------------------//
//  Math Library
//  Matrix 2 Class Definition.
//--------------------------------------------------------------//
//
//   m0 m1
//   m2 m3
//
//--------------------------------------------------------------//

#ifndef __MAT2_H__
#define __MAT2_H__ 1

#include <oxml/Vec2.h>

namespace oxml {

  class Mat2 {
  public:

    Mat2();
    Mat2(float *values);
    Mat2(float value);
    Mat2(const Vec2& a, const Vec2& b); 
    Mat2(const Mat2& copy);
    ~Mat2();

    static Mat2 Identity();
    
    Mat2 Multiply(const Mat2& other) const;
    float Determinant() const;
    Mat2 Adjoint() const;
    Vec2 GetLine(int line) const;
    Vec2 GetColum(int line) const;

    Mat2 Inverse() const;
    Mat2 Transpose() const;

    inline Mat2 operator+(const Mat2& other) const;
    inline void operator+=(const Mat2& other);
    inline Mat2 operator+(float value) const;
    inline void operator+=(float value);
    inline Mat2 operator-(const Mat2& other) const;
    inline void operator-=(const Mat2& other);
    inline Mat2 operator-(float value) const;
    inline void operator-=(float value);

    inline Mat2 operator*(float value) const;
    inline void operator*=(float value);
    inline Mat2 operator/(float value) const;
    inline void operator/=(float value);

    bool operator==(const Mat2& other) const;
    bool operator!=(const Mat2& other) const;
    inline void operator=(const Mat2& other);

    float m[4];
  };


  inline Mat2 Mat2::operator+(const Mat2& other) const {
    return Mat2();
  }

  inline void Mat2::operator+=(const Mat2& other) {
  }

  inline Mat2 Mat2::operator+(float value) const {
    return Mat2();
  }

  inline void Mat2::operator+=(float value) {
  }

  inline Mat2 Mat2::operator-(const Mat2& other) const {
    return Mat2();
  }

  inline void Mat2::operator-=(const Mat2& other) {
  }

  inline Mat2 Mat2::operator-(float value) const {	
    return Mat2();
  }

  inline void Mat2::operator-=(float value) {
  }

  inline Mat2 Mat2::operator*(float value) const {
    return Mat2();
  }

  inline void Mat2::operator*=(float value) {
  }

  inline Mat2 Mat2::operator/(float value) const {
    return Mat2();
  }

  inline void Mat2::operator/=(float value) {

  }

  inline bool Mat2::operator==(const Mat2& other) const {
    return true;
  }

  inline bool Mat2::operator!=(const Mat2& other) const {
    return true;
  }

  inline void Mat2::operator=(const Mat2& other) {
  }

  inline Mat2 Mat2::Identity() {
    return Mat2();
  }

  inline float Mat2::Determinant() const {
    return 0.0f;
  }

  inline Mat2 Mat2::Inverse() const {
    return Mat2();
  }

  inline Mat2 Mat2::Multiply(const Mat2& other) const {
    return Mat2();
  }

  inline Mat2 Mat2::Adjoint() const {
    return Mat2();
  }

  inline Mat2 Mat2::Transpose() const {
    return Mat2();
  }

  inline Vec2 Mat2::GetLine(int line) const {
    return Vec2();
  }

  inline Vec2 Mat2::GetColum(int line) const {	
    return Vec2();
  }

}

#endif
