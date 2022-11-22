#include <oxml/Vec2.h>
#include <math.h>

namespace oxml {

  float Q_rsqrt( float number ){ //Jonh Carmak's square root
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
  }

  const Vec2 Vec2::down = Vec2(0.0f, -1.0f);
  const Vec2 Vec2::left = Vec2(-1.0f, 0.0f);
  const Vec2 Vec2::one = Vec2(1.0f, 1.0f);
  const Vec2 Vec2::right = Vec2(1.0f, 0.0f);
  const Vec2 Vec2::up = Vec2(0.0f, 1.0f);
  const Vec2 Vec2::zero = Vec2(0.0f, 0.0f);

  Vec2::Vec2() {
    x = 0.0f;
    y = 0.0f;
  }

  Vec2::Vec2(float value) {
    this->x = value;
    this->y = value;
  }

  Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
  }

  Vec2::Vec2(float *values) {
    this->x = values[0];
    this->y = values[1];
  }

  Vec2::Vec2(const Vec2& other) {
    x = other.x;
    y = other.y;
  }

  Vec2::~Vec2() {}
  


}