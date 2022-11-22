#ifndef __VEC2_H__
#define __VEC2_H__ 1

namespace oxml {
  
  class Vec2 {
   public:

    Vec2(); //done
    Vec2(float x, float y); //done
    Vec2(const Vec2& copy); //done
    ~Vec2(); //done
 
    Vec2 operator+(const Vec2& other) const; //done
    Vec2 operator+(float value) const; //done
    Vec2& operator+=(const Vec2& other); //done
    Vec2& operator+=(float value); //done
    Vec2 operator-(const Vec2& other) const; //done
    Vec2 operator-(float value) const; //done
    Vec2& operator-(); //done
    Vec2& operator-=(const Vec2& other); //done
    Vec2& operator-=(float value); //done
    bool operator==(const Vec2& other) const; //done
    bool operator!=(const Vec2& other) const; //done
    void operator=(const Vec2& other); //done
    void operator=(float value); //done
    Vec2 operator*(float value) const; //done
    Vec2& operator*=(float value); //done
    Vec2 operator/(float value) const; //done
    Vec2& operator/=(float value); //done

    float Magnitude() const; //done
    float SqrMagnitude() const; //done
    void Normalize(); //done
    Vec2 Normalized() const; //done

    void Scale(const Vec2& scale); //done

    static float Distance(const Vec2& a, const Vec2& b); //done 

    static float Dot(const Vec2& a,const Vec2& b); //done

    static Vec2 Lerp(const Vec2& a, const Vec2& b, float t); //done
    static Vec2 LerpUnclamped(const Vec2& a, const Vec2& b, float t); //done
    static bool Approximately(const Vec2& a, const Vec2& b, float tolerance); //done

    static const Vec2 up;
    static const Vec2 down;
    static const Vec2 right;
    static const Vec2 left;
    static const Vec2 zero;
    static const Vec2 one;

    float x;
    float y;
  };

}

#include "inl/Vec2.inl"

#endif 
