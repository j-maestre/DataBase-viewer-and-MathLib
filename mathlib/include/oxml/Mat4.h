#ifndef __MAT4_H__
#define __MAT4_H__ 1

#include <oxml/Vec3.h>
#include <oxml/Vec4.h>

namespace oxml {

  class Mat4 {
   public:

    Mat4();
    Mat4(float a[16]);
    Mat4(float value);
    Mat4(const Mat4& copy);
    ~Mat4();

    static Mat4 Identity();
    Mat4 Multiply(const Mat4& other) const;

    float Determinant() const;
    Mat4 Adjoint() const;
    bool GetInverse(Mat4* out) const;
    bool Inverse();

    Mat4 Transpose() const;

    static Mat4 Translate(const Vec3& distance);
    static Mat4 Translate(float x, float y, float z);

    static Mat4 Scale(const Vec3& scale);
    static Mat4 Scale(float x, float y, float z);

    static Mat4 RotateX(float radians);
    static Mat4 RotateY(float radians);
    static Mat4 RotateZ(float radians);

    static Mat4 GetTransform(const Vec3& translate, const Vec3& scale,
                        float rotateX, float rotateY, float rotateZ);

    static Mat4 GetTransform(float trans_x, float trans_y, float trans_z,
                        float scale_x, float scale_y, float scale_Z,
                        float rotateX, float rotateY, float rotateZ);

    Mat4 PerspectiveMatrix(float fov, float aspect,
      float near, float far) const;

    Mat4 OrthoMatrix(float right, float left, float top, float valueottom,
      float near, float far) const;

    Vec4 GetColum(int colum) const;
    Vec4 GetLine(int line) const;

    Mat4 operator+(const Mat4& other) const;
    Mat4& operator+=(const Mat4& other);
    Mat4 operator+(float value) const;
    Mat4& operator+=(float value);
    Mat4 operator-(const Mat4& other) const;
    Mat4& operator-=(const Mat4& other);
    Mat4 operator-(float value) const;
    Mat4& operator-=(float value);
    Mat4& operator*=(float value);
    Mat4 operator*(float value) const;
    Mat4& operator/=(float value);
    Mat4 operator/(float value) const;
    bool operator==(const Mat4& other);
    bool operator!=(const Mat4& other);
    void operator=(const Mat4& other);

    float m[16];
  };


  inline Mat4 Mat4::Identity() {
    return Mat4();
  }

  inline Mat4 Mat4::Multiply(const Mat4& other)const  {
    return Mat4();
  }

  inline float Mat4::Determinant() const {
    return 0.0f;
  }

  inline Mat4 Mat4::Adjoint() const {
    Mat4 result;
    return result;
  }

  inline bool Mat4::Inverse() {
    return true;
  }

  inline bool Mat4::GetInverse(Mat4* out) const {
    return true;
  }

  inline Mat4 Mat4::Transpose() const {
    return Mat4();
  }

  inline Mat4 Mat4::Translate(const Vec3& distance){
    return Mat4();
  }

  inline Mat4 Mat4::Translate(float x, float y, float z){
    return Mat4();
  }

  inline Mat4 Mat4::Scale(const Vec3& scale){
    return Mat4();
  }

  inline Mat4 Mat4::Scale(float x, float y, float z){
    return Mat4();
  }

  inline Mat4 Mat4::RotateX(float radians){
    return Mat4();
  }

  inline Mat4 Mat4::RotateY(float radians){
    return Mat4();
  }

  inline Mat4 Mat4::RotateZ(float radians) {
    return Mat4();
  }

  inline Mat4 Mat4::GetTransform(const Vec3& translate,
                  const Vec3& scale,
                  float rotateX, float rotateY,
                  float rotateZ)   {
    return Mat4();
  }

  inline Mat4 Mat4::GetTransform(float trans_x, float trans_y, float trans_z,
    float scale_x, float scale_y, float scale_Z,
    float rotateX, float rotateY, float rotateZ)  {
    
    return Mat4();
  }

  inline Vec4 Mat4::GetColum(int colum) const {
    return Vec4();
  }

  inline Vec4 Mat4::GetLine(int line) const {
    return Vec4();
  }

  inline Mat4 Mat4::PerspectiveMatrix(float fov, float aspect,
    float near, float far) const {
    
    return Mat4();
  }

  inline Mat4 Mat4::OrthoMatrix(float right, float left, float top, float valueottom,
    float near, float far) const {

    return Mat4();
  }

  inline Mat4 Mat4::operator+(const Mat4& other) const {
    return Mat4();
  }

  inline Mat4& Mat4::operator+=(const Mat4& other) {
    return (*this);
  }

  inline Mat4 Mat4::operator+(float value) const {
    return Mat4();
  }

  inline Mat4& Mat4::operator+=(float value) {	
    return (*this);
  }

  inline Mat4 Mat4::operator-(const Mat4& other) const  {
    return Mat4();
  }

  inline Mat4& Mat4::operator-=(const Mat4& other) {
    return (*this);
  }

  inline Mat4 Mat4::operator-(float value) const  {
    return Mat4();
  }

  inline Mat4& Mat4::operator-=(float value) {
    return (*this);
  }

  inline Mat4& Mat4::operator*=(float value) {
    return (*this);
  }

  inline Mat4 Mat4::operator*(float value) const  {
    return Mat4();
  }

  inline Mat4& Mat4::operator/=(float value) {
    return (*this);
  }

  inline Mat4 Mat4::operator/(float value) const {
    return Mat4();
  }

  inline bool Mat4::operator==(const Mat4& other) {
    return true;
  }

  inline bool Mat4::operator!=(const Mat4& other) {
    return false;
  }

  inline void Mat4::operator=(const Mat4& other) {
  }

}

#endif
