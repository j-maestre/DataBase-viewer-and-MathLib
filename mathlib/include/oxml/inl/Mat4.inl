#include <math.h>
#include <oxml/assert.h>

namespace oxml {

  inline Mat4 Mat4::Identity() {
    Mat4 m;
    m.m[0] = 1.0f;
    m.m[1] = 0.0f;
    m.m[2] = 0.0f;
    m.m[3] = 0.0f;
    m.m[4] = 0.0f;
    m.m[5] = 1.0f;
    m.m[6] = 0.0f;
    m.m[7] = 0.0f;
    m.m[8] = 0.0f;
    m.m[9] = 0.0f;
    m.m[10] = 1.0f;
    m.m[11] = 0.0f;
    m.m[12] = 0.0f;
    m.m[13] = 0.0f;
    m.m[14] = 0.0f;
    m.m[15] = 1.0f;
    return m;
  }

  inline Mat4 Mat4::Multiply(const Mat4& other) const {
    Mat4 r;
    r.m[0] = ((this->m[0] * other.m[0]) + (this->m[1] * other.m[4]) + (this->m[2] * other.m[8]) + (this->m[3] * other.m[12]));
    r.m[1] = ((this->m[0] * other.m[1]) + (this->m[1] * other.m[5]) + (this->m[2] * other.m[9]) + (this->m[3] * other.m[13]));
    r.m[2] = ((this->m[0] * other.m[2]) + (this->m[1] * other.m[6]) + (this->m[2] * other.m[10]) + (this->m[3] * other.m[14]));
    r.m[3] = ((this->m[0] * other.m[3]) + (this->m[1] * other.m[7]) + (this->m[2] * other.m[11]) + (this->m[3] * other.m[15]));
    r.m[4] = ((this->m[4] * other.m[0]) + (this->m[5] * other.m[4]) + (this->m[6] * other.m[8]) + (this->m[7] * other.m[12]));
    r.m[5] = ((this->m[4] * other.m[1]) + (this->m[5] * other.m[5]) + (this->m[6] * other.m[9]) + (this->m[7] * other.m[13]));
    r.m[6] = ((this->m[4] * other.m[2]) + (this->m[5] * other.m[6]) + (this->m[6] * other.m[10]) + (this->m[7] * other.m[14]));
    r.m[7] = ((this->m[4] * other.m[3]) + (this->m[5] * other.m[7]) + (this->m[6] * other.m[11]) + (this->m[7] * other.m[15]));
    r.m[8] = ((this->m[8] * other.m[0]) + (this->m[9] * other.m[4]) + (this->m[10] * other.m[8]) + (this->m[11] * other.m[12]));
    r.m[9] = ((this->m[8] * other.m[1]) + (this->m[9] * other.m[5]) + (this->m[10] * other.m[9]) + (this->m[11] * other.m[13]));
    r.m[10] = ((this->m[8] * other.m[2]) + (this->m[9] * other.m[6]) + (this->m[10] * other.m[10]) + (this->m[11] * other.m[14]));
    r.m[11] = ((this->m[8] * other.m[3]) + (this->m[9] * other.m[7]) + (this->m[10] * other.m[11]) + (this->m[11] * other.m[15]));
    r.m[12] = ((this->m[12] * other.m[0]) + (this->m[13] * other.m[4]) + (this->m[14] * other.m[8]) + (this->m[15] * other.m[12]));
    r.m[13] = ((this->m[12] * other.m[1]) + (this->m[13] * other.m[5]) + (this->m[14] * other.m[9]) + (this->m[15] * other.m[13]));
    r.m[14] = ((this->m[12] * other.m[2]) + (this->m[13] * other.m[6]) + (this->m[14] * other.m[10]) + (this->m[15] * other.m[14]));
    r.m[15] = ((this->m[12] * other.m[3]) + (this->m[13] * other.m[7]) + (this->m[14] * other.m[11]) + (this->m[15] * other.m[15]));
    return r;
  }

  inline float Mat4::Determinant() const {
    float det_0[9] = { this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

    float det_1[9] = { this->m[4], this->m[8], this->m[12],
                       this->m[6], this->m[10], this->m[14],
                       this->m[7], this->m[11], this->m[15] };

    float det_2[9] = { this->m[4], this->m[8], this->m[12],
                       this->m[5], this->m[9], this->m[13],
                       this->m[7], this->m[11], this->m[15] };

    float det_3[9] = { this->m[4], this->m[8], this->m[12],
                       this->m[5], this->m[9], this->m[13],
                       this->m[6], this->m[10], this->m[14] };

    return (this->m[0] * Mat3(det_0).Determinant() - this->m[1] * Mat3(det_1).Determinant()
            + this->m[2] * Mat3(det_2).Determinant() - this->m[3] * Mat3(det_3).Determinant());
  }

  inline Mat4 Mat4::Adjoint() const {
    Mat4 result;
    Mat3 aux;
    int aux_index;
    for (int sr = 0; sr < 4; sr++) {
      for (int sc = 0; sc < 4; sc++) {
        aux_index = 0;
        for (int dr = 0; dr < 4; dr++) {
          for (int dc = 0; dc < 4; dc++) {
            if (sc != dc && sr != dr) {
              oxml_assert(aux_index < 9, "Indes out of range");
              aux.m[aux_index] = m[dr * 4 + dc];
              aux_index++;
            }
          }
        }
        result.m[sr * 4 + sc] = powf(-1.0f, sr + sc) * aux.Determinant();
      }
    }
    return result;
  }

  inline bool Mat4::Inverse() {
    float det = Determinant();
    if (det == 0) {
      return false;
    }

    float det = Determinant();
    if (det == 0.0f || det == -0.0f) {
      return false;
    }

    (*this) = ((this->Adjoint().Transpose()) / det);

    return true;
  }

  inline bool Mat4::GetInverse(Mat4& out) const {
    float det = Determinant();
    if (det == 0.0f || det == -0.0f) {
      return false;
    }

    out = ((this->Adjoint().Transpose()) / det);

    return true;
  }

  inline Mat4 Mat4::Transpose() const {
    Mat4 r;
    r.m[0] = m[0];
    r.m[1] = m[4];
    r.m[2] = m[8];
    r.m[3] = m[12];
    r.m[4] = m[1];
    r.m[5] = m[5];
    r.m[6] = m[9];
    r.m[7] = m[13];
    r.m[8] = m[2];
    r.m[9] = m[6];
    r.m[10] = m[10];
    r.m[11] = m[14];
    r.m[12] = m[3];
    r.m[13] = m[7];
    r.m[14] = m[11];
    r.m[15] = m[15];
    return r;
  }

  inline Mat4 Mat4::Translate(const Vec3& position) {

    return Mat4();
  }

  inline Mat4 Mat4::Translate(float x, float y, float z) {
    return Mat4();
  }

  inline Mat4 Mat4::Scale(const Vec3& scale) {
    Mat4 identity = Identity();
    identity.m[0] = scale.x;
    identity.m[5] = scale.y;
    identity.m[10] = scale.z;
    return identity;
  }

  inline Mat4 Mat4::Scale(float x, float y, float z) {
    return Mat4();
  }

  inline Mat4 Mat4::RotateX(float radians) {
    Mat4 identity = Identity();
    identity.m[5] = cosf(radians);
    identity.m[6] = -sinf(radians);
    identity.m[9] = sinf(radians);
    identity.m[10] = cos(radians);

    return identity;
  }

  inline Mat4 Mat4::RotateY(float radians) {
    Mat4 identity = Identity();

    identity.m[0] = cosf(radians);
    identity.m[2] = sinf(radians);
    
    identity.m[8] = -sinf(radians);
    identity.m[10] = -cosf(radians);

    return identity;
  }

  inline Mat4 Mat4::RotateZ(float radians) {
    Mat4 identity = Identity();

    identity.m[0] = cosf(radians);
    identity.m[1] = -sinf(radians);
    identity.m[4] = sinf(radians);
    identity.m[5] = cosf(radians);

    return identity;
  }

  inline Mat4 Mat4::TRS(const Vec3& translate,
    const Vec3& scale, const Vec3& rotation) {
    return Mat4();
  }

  inline Mat4 Mat4::TRS(float trans_x, float trans_y, float trans_z, float scale_x, float scale_y, float scale_Z, float rotateX, float rotateY, float rotateZ) {

    return Mat4();
  }

  inline Vec4 Mat4::GetColum(int colum) const {
    return Vec4((m[0 * 4 + colum], m[1 * 4 + colum], m[2 * 4 + colum], m[3 * 4 + colum]));
  }

  inline Vec4 Mat4::GetRow(int row) const {
    return Vec4(m[row * 4 + 0], m[row * 4 + 1], m[row * 4 + 2], m[row * 4 + 3]);
  }

  inline Mat4 Mat4::Perspective(float fov, float aspect, float near, float far) {

    return Mat4();
  }

  inline Mat4 Mat4::Ortho(float right, float left, float top, float valueottom, float near, float far) {

    return Mat4();
  }

  inline Mat4 Mat4::operator+(const Mat4& other) const {
    Mat4 m;
    m.m[0] = other.m[0] + this->m[0];
    m.m[1] = other.m[1] + this->m[1];
    m.m[2] = other.m[2] + this->m[2];
    m.m[3] = other.m[3] + this->m[3];
    m.m[4] = other.m[4] + this->m[4];
    m.m[5] = other.m[5] + this->m[5];
    m.m[6] = other.m[6] + this->m[6];
    m.m[7] = other.m[7] + this->m[7];
    m.m[8] = other.m[8] + this->m[8];
    m.m[9] = other.m[9] + this->m[9];
    m.m[10] = other.m[10] + this->m[10];
    m.m[11] = other.m[11] + this->m[11];
    m.m[12] = other.m[12] + this->m[12];
    m.m[13] = other.m[13] + this->m[13];
    m.m[14] = other.m[14] + this->m[14];
    m.m[15] = other.m[15] + this->m[15];
    return m;
  }

  inline Mat4& Mat4::operator+=(const Mat4& other) {
    this->m[0] += other.m[0];
    this->m[1] += other.m[1];
    this->m[2] += other.m[2];
    this->m[3] += other.m[3];
    this->m[4] += other.m[4];
    this->m[5] += other.m[5];
    this->m[6] += other.m[6];
    this->m[7] += other.m[7];
    this->m[8] += other.m[8];
    this->m[9] += other.m[9];
    this->m[10] += other.m[10];
    this->m[11] += other.m[11];
    this->m[12] += other.m[12];
    this->m[13] += other.m[13];
    this->m[14] += other.m[14];
    this->m[15] += other.m[15];
    return (*this);
  }

  inline Mat4 Mat4::operator+(float value) const {
    Mat4 m;
    m.m[0] = value + this->m[0];
    m.m[1] = value + this->m[1];
    m.m[2] = value + this->m[2];
    m.m[3] = value + this->m[3];
    m.m[4] = value + this->m[4];
    m.m[5] = value + this->m[5];
    m.m[6] = value + this->m[6];
    m.m[7] = value + this->m[7];
    m.m[8] = value + this->m[8];
    m.m[9] = value + this->m[9];
    m.m[10] = value + this->m[10];
    m.m[11] = value + this->m[11];
    m.m[12] = value + this->m[12];
    m.m[13] = value + this->m[13];
    m.m[14] = value + this->m[14];
    m.m[15] = value + this->m[15];
    return m;
  }

  inline Mat4& Mat4::operator+=(float value) {
    this->m[0] += value;
    this->m[1] += value;
    this->m[2] += value;
    this->m[3] += value;
    this->m[4] += value;
    this->m[5] += value;
    this->m[6] += value;
    this->m[7] += value;
    this->m[8] += value;
    this->m[9] += value;
    this->m[10] += value;
    this->m[11] += value;
    this->m[12] += value;
    this->m[13] += value;
    this->m[14] += value;
    this->m[15] += value;
    return (*this);
  }

  inline Mat4 Mat4::operator-(const Mat4& other) const {
    Mat4 m;
    m.m[0] = this->m[0] - other.m[0];
    m.m[1] = this->m[1] - other.m[1];
    m.m[2] = this->m[2] - other.m[2];
    m.m[3] = this->m[3] - other.m[3];
    m.m[4] = this->m[4] - other.m[4];
    m.m[5] = this->m[5] - other.m[5];
    m.m[6] = this->m[6] - other.m[6];
    m.m[7] = this->m[7] - other.m[7];
    m.m[8] = this->m[8] - other.m[8];
    m.m[9] = this->m[9] - other.m[9];
    m.m[10] = this->m[10] - other.m[10];
    m.m[11] = this->m[11] - other.m[11];
    m.m[12] = this->m[12] - other.m[12];
    m.m[13] = this->m[13] - other.m[13];
    m.m[14] = this->m[14] - other.m[14];
    m.m[15] = this->m[15] - other.m[15];
    return m;
  }

  inline Mat4& Mat4::operator-=(const Mat4& other) {
    this->m[0] -= other.m[0];
    this->m[1] -= other.m[1];
    this->m[2] -= other.m[2];
    this->m[3] -= other.m[3];
    this->m[4] -= other.m[4];
    this->m[5] -= other.m[5];
    this->m[6] -= other.m[6];
    this->m[7] -= other.m[7];
    this->m[8] -= other.m[8];
    this->m[9] -= other.m[9];
    this->m[10] -= other.m[10];
    this->m[11] -= other.m[11];
    this->m[12] -= other.m[12];
    this->m[13] -= other.m[13];
    this->m[14] -= other.m[14];
    this->m[15] -= other.m[15];
    return (*this);
  }

  inline Mat4 Mat4::operator-(float value) const {
    Mat4 m;
    m.m[0] = this->m[0] - value;
    m.m[1] = this->m[1] - value;
    m.m[2] = this->m[2] - value;
    m.m[3] = this->m[3] - value;
    m.m[4] = this->m[4] - value;
    m.m[5] = this->m[5] - value;
    m.m[6] = this->m[6] - value;
    m.m[7] = this->m[7] - value;
    m.m[8] = this->m[8] - value;
    m.m[9] = this->m[9] - value;
    m.m[10] = this->m[10] - value;
    m.m[11] = this->m[11] - value;
    m.m[12] = this->m[12] - value;
    m.m[13] = this->m[13] - value;
    m.m[14] = this->m[14] - value;
    m.m[15] = this->m[15] - value;
    return m;
  }

  inline Mat4& Mat4::operator-=(float value) {
    this->m[0] -= value;
    this->m[1] -= value;
    this->m[2] -= value;
    this->m[3] -= value;
    this->m[4] -= value;
    this->m[5] -= value;
    this->m[6] -= value;
    this->m[7] -= value;
    this->m[8] -= value;
    this->m[9] -= value;
    this->m[10] -= value;
    this->m[11] -= value;
    this->m[12] -= value;
    this->m[13] -= value;
    this->m[14] -= value;
    this->m[15] -= value;
    return (*this);
  }

  inline Mat4& Mat4::operator*=(float value) {
    this->m[0] *= value;
    this->m[1] *= value;
    this->m[2] *= value;
    this->m[3] *= value;
    this->m[4] *= value;
    this->m[5] *= value;
    this->m[6] *= value;
    this->m[7] *= value;
    this->m[8] *= value;
    this->m[9] *= value;
    this->m[10] *= value;
    this->m[11] *= value;
    this->m[12] *= value;
    this->m[13] *= value;
    this->m[14] *= value;
    this->m[15] *= value;
    return (*this);
  }

  inline Mat4 Mat4::operator*(float value) const {
    Mat4 m;
    m.m[0] = value * this->m[0];
    m.m[1] = value * this->m[1];
    m.m[2] = value * this->m[2];
    m.m[3] = value * this->m[3];
    m.m[4] = value * this->m[4];
    m.m[5] = value * this->m[5];
    m.m[6] = value * this->m[6];
    m.m[7] = value * this->m[7];
    m.m[8] = value * this->m[8];
    m.m[9] = value * this->m[9];
    m.m[10] = value * this->m[10];
    m.m[11] = value * this->m[11];
    m.m[12] = value * this->m[12];
    m.m[13] = value * this->m[13];
    m.m[14] = value * this->m[14];
    m.m[15] = value * this->m[15];
    return m;
  }

  inline Mat4& Mat4::operator/=(float value) {
    this->m[0] /= value;
    this->m[1] /= value;
    this->m[2] /= value;
    this->m[3] /= value;
    this->m[4] /= value;
    this->m[5] /= value;
    this->m[6] /= value;
    this->m[7] /= value;
    this->m[8] /= value;
    this->m[9] /= value;
    this->m[10] /= value;
    this->m[11] /= value;
    this->m[12] /= value;
    this->m[13] /= value;
    this->m[14] /= value;
    this->m[15] /= value;
    return (*this);
  }

  inline Mat4 Mat4::operator/(float value) const {
    Mat4 m;
    m.m[0] = this->m[0] / value;
    m.m[1] = this->m[1] / value;
    m.m[2] = this->m[2] / value;
    m.m[3] = this->m[3] / value;
    m.m[4] = this->m[4] / value;
    m.m[5] = this->m[5] / value;
    m.m[6] = this->m[6] / value;
    m.m[7] = this->m[7] / value;
    m.m[8] = this->m[8] / value;
    m.m[9] = this->m[9] / value;
    m.m[10] = this->m[10] / value;
    m.m[11] = this->m[11] / value;
    m.m[12] = this->m[12] / value;
    m.m[13] = this->m[13] / value;
    m.m[14] = this->m[14] / value;
    m.m[15] = this->m[15] / value;
    return m;
  }

  inline bool Mat4::operator==(const Mat4& other) const {
    bool rslt = true;
    for (int i = 0; i < 16 && rslt; i++) {
      rslt = (this->m[i] == other.m[i]);
    }
    return rslt;
  }

  inline bool Mat4::operator!=(const Mat4& other) const {
    bool rslt = true;
    for (int i = 0; i < 16 && rslt; i++) {
      rslt = (this->m[i] != other.m[i]);
    }
    return rslt;
  }

  inline Mat4& Mat4::operator=(const Mat4& other) {
    this->m[0] = other.m[0];
    this->m[1] = other.m[1];
    this->m[2] = other.m[2];
    this->m[3] = other.m[3];
    this->m[4] = other.m[4];
    this->m[5] = other.m[5];
    this->m[6] = other.m[6];
    this->m[7] = other.m[7];
    this->m[8] = other.m[8];
    this->m[9] = other.m[9];
    this->m[10] = other.m[10];
    this->m[11] = other.m[11];
    this->m[12] = other.m[12];
    this->m[13] = other.m[13];
    this->m[14] = other.m[14];
    this->m[15] = other.m[15];
    return *this;
  }

}