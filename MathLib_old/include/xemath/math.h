/*
    * Math library
    * Author Xema Maestre
    * <maestrequi@esat-alumni.com>
*/

#ifndef __XEMATH_H__
#define __XEMATH_H__ 1

namespace xemath{
    struct Vec2{
        float x,y;
    };
    struct Vec3{
        float x,y,z;
    };
    struct Vec4{
        float x,y,z,w;
    };
    struct Mat2{
        float m[4];
    };
    struct Mat31{
        float m[3];
    };

    struct Mat3{
        float x,y,z;
    };

    float ToRadianes(float valor);
    Vec2 SumVec2(Vec2 v1, Vec2 v2);
    Vec2 RestVec2(Vec2 v1, Vec2 v2);
    Vec3 SumVec3(Vec3 vec1, Vec3 vec2);
    Vec4 SumVec4(Vec4 vec1, Vec4 vec2);
    Mat2 SumMat2(Mat2 mat1, Mat2 mat2);
    Mat31 SumMat31(Mat31 mat1, Mat31 mat2);
    Vec2 Vec2MultMatVec2(Mat2 mat, Vec2 vec);
    Vec2 MultVec2(Vec2 vec1, Vec2 vec2);
    bool CheckNormalizedVec2(Vec2 vec);
    Vec2 Vec2Normalize(Vec2 vec);
    float Vec2Modulo(Vec2 vec);
    Vec3 Vec3Normalize(Vec3 vec);
    Vec2 RotateVec2(Vec2 vec, float angle);
    void DebugVec2(Vec2 Vec);
    void DebugVec3(Vec3 Vec);
    void DebugVec4(Vec4 Vec);
    void DebugMat2(Mat2 mat);
    Vec2 ScalateVec2(Vec2 vec, float size);
    Mat3 Mat32x2Solver(Mat3 mat1,Mat3 mat2);
    Mat3 Mat32x2Solver(Mat3 mat1,Mat3 mat2,Mat3 mat3);

    Mat3x3 MatIdentity();

}



#endif