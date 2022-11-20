#ifndef __VEC2_H__
#define __VEC2_H__ 1

namespace oxml {
  
  class Vec2 {
   public:

    Vec2();
    Vec2(float x, float y);
    Vec2(const Vec2& copy);
    ~Vec2();

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator+(float value);
    Vec2& operator+=(const Vec2& other);
    Vec2& operator+=(float value);
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator-(float value) const;
    Vec2& operator-();
    Vec2& operator-=(const Vec2& other);
    Vec2& operator-=(float value);
    bool operator==(const Vec2& other) const;
    bool operator!=(const Vec2& other) const;
    void operator=(const Vec2& other);
    void operator=(float value);
    Vec2 operator*(float value) const;
    Vec2& operator*=(float value);
    Vec2 operator/(float value) const;
    Vec2& operator/=(float value);

    float Magnitude() const;
    float SqrMagnitude() const;
    void Normalize();
    Vec2 Normalized() const;

    void Scale(const Vec2& scale);

    static float Distance(const Vec2& a, const Vec2& b);

    static float Dot(const Vec2& a,const Vec2& b);

    static Vec2 Lerp(const Vec2& a, const Vec2& b, float t);
    static Vec2 LerpUnclamped(const Vec2& a, const Vec2& b, float t);
    static bool Approximately(const Vec2& a, const Vec2& b, float tolerance);

    static const Vec2 up;
    static const Vec2 down;
    static const Vec2 right;
    static const Vec2 left;
    static const Vec2 zero;
    static const Vec2 one;

    float x;
    float y;
  };


  inline Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2();
  }

  inline Vec2 Vec2::operator+(float value) {
    return Vec2();
  }

  inline Vec2& Vec2::operator+=(const Vec2& other){
    return *this;
  }

  inline Vec2& Vec2::operator+=(float value){
    return *this;
  }

  inline Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2();
  }

  inline Vec2 Vec2::operator-(float value) const {
    return Vec2();
  }

  inline Vec2& Vec2::operator-() {
    return *this;
  }

  inline Vec2& Vec2::operator-=(const Vec2& other) {
    return *this;
  }

  inline Vec2& Vec2::operator-=(float value){
    return *this;
  }

  inline bool Vec2::operator==(const Vec2& value) const {
    return false;
  }

  inline bool Vec2::operator!=(const Vec2& value) const {
    return true;
  }

  inline void Vec2::operator=(const Vec2& other) {
  }

  inline void Vec2::operator=(float value) {
  }

  inline Vec2 Vec2::operator*(float value) const {
    return Vec2();
  }

  inline Vec2& Vec2::operator*=(float value) {  
    return *this;
  }

  inline Vec2 Vec2::operator/(float value) const {
    return Vec2();
  }

  inline Vec2& Vec2::operator/=(float value) {
    return *this;
  }

  inline float Vec2::Magnitude() const {
    return 0.0f;
  }

  inline void Vec2::Normalize() {  
  }

  inline Vec2 Vec2::Normalized() const {
    return Vec2();
  }

  inline void Vec2::Scale(const Vec2& scale){

  }

  inline float Vec2::SqrMagnitude() const {
    return 0.0f;
  }

  inline float Vec2::Distance(const Vec2& a, const Vec2& b) {
    return 0.0f;
  }

  inline Vec2 Vec2::Lerp(const Vec2& a, const Vec2& b, float t) {
    return Vec2();
  }

  inline Vec2 Vec2::LerpUnclamped(const Vec2& a, const Vec2& b, float t) {
    return Vec2();
  }

  inline float Vec2::Dot(const Vec2& a, const Vec2& b) {
    return 0.0f;
  }

}


#endif 
