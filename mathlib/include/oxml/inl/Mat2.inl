namespace oxml {

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