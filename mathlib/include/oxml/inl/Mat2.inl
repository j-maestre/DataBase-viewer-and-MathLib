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
    float points[4];
    points[0] = 1;
    points[1] = 0;
    points[2] = 0;
    points[3] = 1;
    return Mat2(points);
  }

  inline float Mat2::Determinant() const {
    return (this->m[0] * this->m[3]) - (this->m[1] * this->m[2]);
  }

  inline Mat2 Mat2::Inverse() const {
    float determinante = this->Determinant();
    Mat2 inverse = this->Adjoint();
    return Mat2();
  }

  inline Mat2 Mat2::Multiply(const Mat2& other) const {
    return Mat2();
  }

  inline Mat2 Mat2::Adjoint() const {
    float points[4];
    points[0] = this->m[3];
    points[1] = this->m[2];
    points[2] = this->m[1];
    points[3] = this->m[0];
    return Mat2(points);
  }

  inline Mat2 Mat2::Transpose() const {
    float points[4] ={m[0],m[2],m[1],m[3]};
    return Mat2(points);
  }

  inline Vec2 Mat2::GetLine(int line) const {
    //Assert if line >1
    return Vec2(m[line*2],m[line*2+1]);
  }

  inline Vec2 Mat2::GetColum(int line) const{
    //Assert if colum >1

    //return Vec2(m[line*2],m[line+1*2]);
  }

}