//--------------------------------------------------------------//
//  Math Library
//  Matrix 3 Class Definition.
//--------------------------------------------------------------//
//
//   m0 m1 m2
//   m3 m4 m5
//   m6 m7 m8
//
//--------------------------------------------------------------//
#ifndef __MAT3_H__
#define __MAT3_H__ 1

#include <oxml/Vec2.h>
#include <oxml/Vec3.h>

namespace oxml {

  class Mat3 {
   public:

    Mat3();
    Mat3(float *values);
    Mat3(float value);
    Mat3(const Vec3& a, const Vec3& b, const Vec3& c);

    Mat3(const Mat3& copy);
    ~Mat3();

    static Mat3 Identity();

    Mat3 Multiply(const Mat3& other) const;

    float Determinant() const;

    Mat3 Adjoint() const;
    bool GetInverse(Mat3& out) const;
    bool Inverse();

    Mat3 Transpose() const;

    static Mat3 Translate(const Vec2& position);
    static Mat3 Translate(float x, float y);

    Vec3 GetColum(int colum) const;
    Vec3 GetRow(int row) const;

    inline Mat3 operator+(const Mat3& other) const;
    inline Mat3& operator+=(const Mat3& other);
    inline Mat3 operator+(float value) const;
    inline Mat3& operator+=(float value);
    inline Mat3 operator-(const Mat3& other) const;
    inline Mat3& operator-=(const Mat3& other);
    inline Mat3 operator-(float value) const;
    inline Mat3& operator-=(float value);
    inline Mat3 operator*(float value) const;
    inline Mat3& operator*=(float value);
    inline Mat3 operator/(float value) const;
    inline Mat3& operator/=(float value);
    bool operator==(const Mat3& other) const;
    bool operator!=(const Mat3& other) const;
    inline void operator=(const Mat3& other);

    float m[9];
  };


  inline Mat3 Mat3::operator+(const Mat3& other) const {
    return Mat3();
  }

  inline Mat3& Mat3::operator+=(const Mat3& other) {
    return (*this);
  }

  inline Mat3 Mat3::operator+(float value) const {
    return Mat3();
  }

  inline Mat3& Mat3::operator+=(float value) {	
    return (*this);
  }

  inline Mat3 Mat3::operator-(const Mat3& other) const {
    return Mat3();
  }

  inline Mat3& Mat3::operator-=(const Mat3& other) {
    return (*this);
  }

  inline Mat3 Mat3::operator-(float value) const {
    return Mat3();
  }

  inline Mat3& Mat3::operator-=(float value) {
    return (*this);
  }

  inline Mat3 Mat3::operator*(float value) const {
    return Mat3();
  }

  inline Mat3& Mat3::operator*=(float value) {
    return (*this);
  }

  inline Mat3 Mat3::operator/(float value) const {
    return Mat3();
  }

  inline Mat3& Mat3::operator/=(float value) {
    return (*this);
  }

  inline bool Mat3::operator==(const Mat3& other) const {
    return true;
  }

  inline bool Mat3::operator!=(const Mat3& other) const {
    return true;
  }

  inline void Mat3::operator=(const Mat3& other) {
  }

  inline Mat3 Mat3::Identity() {
    return Mat3();
  }

  inline float Mat3::Determinant() const {
    return 42.0f;
  }

  inline bool Mat3::GetInverse(Mat3& out) const {
    return true;
  }

  inline bool Mat3::Inverse() {	
    return true;
  }

  inline Mat3 Mat3::Translate(const Vec2& mov_vector) {	
    return Mat3();
  }

  inline Mat3 Mat3::Translate(float x, float y) {
    return Mat3();
  }

  inline Mat3 Mat3::Multiply(const Mat3& other) const {
    return Mat3();
  }

  inline Mat3 Mat3::Adjoint() const {
    return Mat3();
  }

  inline Mat3 Mat3::Transpose() const {
    return Mat3();
  }

  inline Vec3 Mat3::GetColum(int colum) const {
    return Vec3();
  }

  inline Vec3 Mat3::GetRow(int row) const {
    return Vec3();
  }

}

#endif 