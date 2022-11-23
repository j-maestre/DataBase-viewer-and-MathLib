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
    for (int i = 0; i < 9; i++){
      m[i] = other.m[i];
    }
  }

  inline Mat3 Mat3::Identity() {
    Mat3 m;
    m.m[0] = 1.0f; m.m[1] = 0.0f; m.m[2] = 0.0f;
    m.m[3] = 0.0f; m.m[4] = 1.0f; m.m[5] = 0.0f;
    m.m[6] = 0.0f; m.m[7] = 0.0f; m.m[8] = 1.0f;
    return Mat3();
  }

  inline float Mat3::Determinant() const {
    return ((m[0]* m[4]*m[8]) + (m[3]*m[7]*m[2]) + (m[6]*m[1]*m[5])) - ((m[2]* m[4]*m[6]) + (m[5]*m[7]*m[0]) + (m[8]*m[1]*m[3]));
  }

  inline bool Mat3::GetInverse(Mat3& out) const {
    return true;
  }

  inline bool Mat3::Inverse() {
    return true;
  }

  inline Mat3 Mat3::Translate(const Vec2& mov_vector) {
    Mat3 aux(Identity());
    aux.m[2] = mov_vector.x;
    aux.m[5] = mov_vector.y;
    return aux;
  }

  inline Mat3 Mat3::Translate(float x, float y) {
    Mat3 aux(Identity());
    aux.m[2] = x;
    aux.m[5] = y;
    return aux;
  }
  inline Mat3 Mat3::Rotate(const float rotation) {
    Mat3 aux(Identity());
    aux.m[0] = cosf(rotation);
    aux.m[1] = sinf(rotation);
    aux.m[3] = sin(rotation) * -1.0f;
    aux.m[4] = cosf(rotation);
  }

  inline Mat3 Mat3::Multiply(const Mat3& other) const {
    Mat3 result;
    Vec3 fila;
    Vec3 columna;

    // Primera posicion
    fila.x = m[0]; fila.y = m[1]; fila.z = m[2];
    columna.x = other.m[0];columna.y = other.m[3]; columna.z = other.m[6];
    result.m[0] = Vec3::Dot(fila,columna);
    
    //Segunda posicion
    columna.x = other.m[1];columna.y = other.m[4]; columna.z = other.m[7];
    result.m[1] = Vec3::Dot(fila,columna);
    
    //Tercera posicion
    columna.x = other.m[2];columna.y = other.m[5]; columna.z = other.m[8];
    result.m[2] = Vec3::Dot(fila,columna);

    //Cuarta posicion
    fila.x = m[3]; fila.y = m[4]; fila.z = m[5];
    columna.x = other.m[0];columna.y = other.m[3]; columna.z = other.m[6];
    result.m[3] = Vec3::Dot(fila,columna);
    
    //Quinta posicion
    columna.x = other.m[1];columna.y = other.m[4]; columna.z = other.m[7];
    result.m[4] = Vec3::Dot(fila,columna);
    
    //Sexta posicion
    columna.x = other.m[2];columna.y = other.m[5]; columna.z = other.m[8];
    result.m[5] = Vec3::Dot(fila,columna);

    //Septima posicion
    fila.x = m[6]; fila.y = m[7]; fila.z = m[8];
    columna.x = other.m[0];columna.y = other.m[3]; columna.z = other.m[6];
    result.m[6] = Vec3::Dot(fila,columna);
    
    //Octava posicion
    columna.x = other.m[1];columna.y = other.m[4]; columna.z = other.m[7];
    result.m[7] = Vec3::Dot(fila,columna);
    
    //Novena posicion
    columna.x = other.m[2];columna.y = other.m[5]; columna.z = other.m[8];
    result.m[8] = Vec3::Dot(fila,columna);

    return result;
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