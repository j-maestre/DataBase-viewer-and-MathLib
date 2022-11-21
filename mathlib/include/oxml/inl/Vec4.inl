namespace oxml {

  inline float Vec4::Magnitude() const {
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

  inline float Vec4::Dot(const Vec4& a, const Vec4& b) {
    return 0.0f;
  }

  inline Vec4 Vec4::Lerp(const Vec4& a, const Vec4& b, float index) {
    return Vec4();
  }

  inline Vec4 Vec4::operator+(const Vec4& other) const {
    return Vec4();
  }

  inline Vec4 Vec4::operator+(float value) const {
    return Vec4();
  }

  inline void Vec4::operator+=(const Vec4& other) {

  }

  inline void Vec4::operator+=(float value) {

  }

  inline Vec4 Vec4::operator-(const Vec4& other) const {
    return Vec4();
  }

  inline Vec4 Vec4::operator-(float value) const {
    return Vec4();
  }

  inline void Vec4::operator -=(const Vec4& other) {

  }

  inline void Vec4::operator -=(float value) {

  }

  inline Vec4 Vec4::operator*(float value) const {
    return Vec4();
  }

  inline void Vec4::operator*=(float value) {
  }

  inline Vec4 Vec4::operator/(float value) const {
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