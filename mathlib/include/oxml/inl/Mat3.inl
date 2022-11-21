namespace oxml {

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