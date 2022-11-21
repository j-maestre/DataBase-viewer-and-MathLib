#ifndef __VEC4_H__
#define __VEC4_H__ 1

#include <oxml/Vec3.h>
#include <oxml/Mat3.h>

namespace oxml {

  class Vec4 {
   public:

    Vec4();
    Vec4(float x, float y, float z, float w);
    Vec4(const Vec3& v, float w);
    Vec4(float a);
    Vec4(float *values);
    Vec4(const Vec4& other);
    ~Vec4();
    
    Vec4 operator+(const Vec4& other) const;
    Vec4 operator+(float value) const;
    void operator+=(const Vec4& other);
    void operator+=(float value);
    Vec4 operator-(const Vec4& other) const;
    Vec4 operator-(float value) const;
    void operator -=(const Vec4& other);
    void operator -=(float value);

    Vec4 operator*(float value) const;
    void operator*=(float value);
    Vec4 operator/(float value) const;
    void operator/=(float value);
    bool operator==(const Vec4& other);
    bool operator!=(const Vec4& other);
    void operator=(const Vec4& other);

    float Magnitude() const;
    void Normalize();
    Vec4 Normalized() const;
    void Scale(Vec4 scale);
    float SqrMagnitude() const;

    static float Distance(const Vec4& a, const Vec4& b);
    static float Dot(const Vec4& a, const Vec4& b);
    static Vec4 Lerp(const Vec4& a, const Vec4& b, float index);	
    static bool Approximately(const Vec4& a, const Vec4& b, float tolerance);

    static const Vec4 one;
    static const Vec4 zero;

    float x;
    float y;
    float z;
    float w;

  };

}

#include "inl/Vec4.inl"

#endif 
