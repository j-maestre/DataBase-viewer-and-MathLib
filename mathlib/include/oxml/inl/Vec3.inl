namespace oxml {

  inline float Vec3::Magnitude() const {
    return 0.0f;
  }

  inline void Vec3::Normalize() {

    float inverseMagnitude = 1.0f / Magnitude();
    *this *= inverseMagnitude;
  }

  inline Vec3 Vec3::Normalized() const {
    return Vec3();
  }

  inline float Vec3::Dot(const Vec3& a, const Vec3& other) {
    return 0.0f;
  }

  inline float Vec3::Angle(const Vec3& a, const Vec3& other) {
    return 0.0f;
  }

  inline Vec3 Vec3::Cross(const Vec3& a, const Vec3& other) {
    return Vec3();
  }

  inline float Vec3::SqrMagnitude() const {
    return 0.0f;
  }

  inline void Vec3::Scale(const Vec3& other) {
  }

  inline Vec3 Vec3::Lerp(const Vec3& a, const Vec3& b, float t) {
    return Vec3();
  }

  inline Vec3 Vec3::LerpUnclamped(const Vec3& a, const Vec3& b, float t) {
    return Vec3();
  }

  inline float Vec3::Distance(const Vec3& a, const Vec3& b) {
    return 0.0f;
  }

  inline Vec3 Vec3::Reflect(const Vec3& direction, const Vec3& normal) {
    return Vec3();
  }

  inline Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3();
  }

  inline Vec3 Vec3::operator+(float value) const {
    return Vec3();
  }

  inline Vec3& Vec3::operator+=(const Vec3& other) {
    return *this;
  }

  inline Vec3& Vec3::operator+=(float value) {
    return *this;
  }

  inline Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3();
  }

  inline Vec3 Vec3::operator-(float value) const {
    return Vec3();
  }

  inline Vec3& Vec3::operator-=(const Vec3& other) {
    return *this;
  }

  inline Vec3& Vec3::operator-=(float value) {
    return *this;
  }

  inline bool Vec3::operator==(const Vec3& other) const {
    return true;
  }

  inline bool Vec3::operator!=(const Vec3& other) const {
    return true;
  }

  inline void Vec3::operator=(const Vec3& other) {
  }

  inline void Vec3::operator=(float value) {
  }

  inline Vec3 Vec3::operator*(float value) const {
    return Vec3();
  }

  inline Vec3& Vec3::operator*=(float value) {
    return *this;
  }

  inline Vec3 Vec3::operator/(float value) const {
    return Vec3();
  }

  inline Vec3& Vec3::operator/=(float value) {
    return *this;
  }

}