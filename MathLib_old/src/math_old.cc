#include <xemath/math.h>
#include <stdio.h>
#include <math.h>

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
struct Mat3x3{
  float p[9];
};


  float ToRadianes(float valor){
    return valor*(3.1415f/180.0f);
  }

  //Sumar dos vectores2
  Vec2 SumVec2(Vec2 v1, Vec2 v2){
    Vec2 aux = {v1.x+v2.x,v1.y+v2.y};
    return aux;
  }
  //Restar dos vectores2
  Vec2 RestVec2(Vec2 v1, Vec2 v2){
    Vec2 aux = {v1.x-v2.x,v1.y-v2.y};
    return aux;
  }

  //Sumar dos vectores3
  Vec3 SumVec3(Vec3 vec1, Vec3 vec2){
    Vec3 aux={
      (vec1.x+vec2.x),
      (vec1.y+vec2.y),
      (vec1.z+vec2.z)
    };
    return aux;
  }

  //Sumar dos vectores4
  Vec4 SumVec4(Vec4 vec1, Vec4 vec2){
    Vec4 aux={
      (vec1.x+vec2.x),
      (vec1.y+vec2.y),
      (vec1.z+vec2.z),
      (vec1.w+vec2.w)
    };
    return aux;
  }

  //Sumar dos Mat2
  Mat2 SumMat2(Mat2 mat1, Mat2 mat2){
    Mat2 aux;
    aux.m[0] = mat1.m[0]+mat2.m[0];
    aux.m[1] = mat1.m[1]+mat2.m[1];
    aux.m[2] = mat1.m[2]+mat2.m[2];
    aux.m[3] = mat1.m[3]+mat2.m[3];
    return aux;
  }

  //Sumar dos Mat31
  Mat31 SumMat31(Mat31 mat1, Mat31 mat2){
    Mat31 aux;
    aux.m[0] = mat1.m[0]+mat2.m[0];
    aux.m[1] = mat1.m[1]+mat2.m[1];
    aux.m[2] = mat1.m[2]+mat2.m[2];
    return aux;
  }

  //Normalizar Mat31
  
  //Multiplicar Mat2 * Vector2
  Vec2 Vec2MultMatVec2(Mat2 mat, Vec2 vec){
    Vec2 aux={
      mat.m[0] * vec.x + mat.m[2] * vec.y,
      mat.m[1] * vec.x + mat.m[3] * vec.y
    };
    return aux;
  }

  //Multiplicar Vec2 * Vec2
  Vec2 MultVec2(Vec2 vec1, Vec2 vec2){
    Vec2 aux = {vec1.x * vec2.x, vec1.y * vec2.y};
    return aux;
  }

    //Si lo divido entre su modulo me tiene que dar 1
    //NO FUNCIONA

  bool CheckNormalizedVec2(Vec2 vec){
    bool normalizado = true;
    // v = raiz cuadrada de x^2+y^2
    float modulo = (float)sqrt(vec.x*vec.x) + sqrt(vec.y * vec.y);
    if(modulo != 1) normalizado = false;

    return normalizado;
  }

  //Normalizar Vec2
  Vec2 Vec2Normalize(Vec2 vec){
    float hipotenusa=(vec.x*vec.x)+(vec.y*vec.y);
    hipotenusa = (float)sqrt(hipotenusa);
    Vec2 aux = {
      vec.x/hipotenusa,
      vec.y/hipotenusa
    };
    return aux;
  }

  float Vec2Modulo(Vec2 vec){
    //Raiz de x^2 + y^2
    float aux = (float)sqrt(((vec.x*vec.x)+(vec.y*vec.y)));
    return aux;
  }
  //Normalizar Vector3
  Vec3 Vec3Normalize(Vec3 vec){
    float hipotenusa=(vec.x*vec.x)+(vec.y*vec.y)+(vec.z*vec.z);
    hipotenusa = (float)sqrt(hipotenusa);
    Vec3 aux = {
      vec.x/hipotenusa,
      vec.y/hipotenusa,
      vec.z/hipotenusa
    };
    return aux;
  }

  Vec2 RotateVec2(Vec2 vec, float angle){
    angle = ToRadianes(angle);
    Vec2 aux;
    aux.x = (vec.x * cos(angle)) - (vec.y * sin(angle));
    aux.y = (vec.x * sin(angle)) + (vec.y * cos(angle));
    return aux;
  }

  //Debug Vector2
  void DebugVec2(Vec2 vector){
    printf("X:[%f] Y:[%f]\n",vector.x,vector.y);
  }
  //Debug Vector3
  void DebugVector3(Vec3 vector){
    printf("X:[%f] Y:[%f] Z:[%f]\n",vector.x,vector.y,vector.z);
  }
  //Debug Vector4
  void DebugVector4(Vec4 vector){
    printf("X:[%f] Y:[%f] Z:[%f] W:[%f]\n",vector.x,vector.y,vector.z,vector.w);
  }
  //Debug Mat2
  void DebugMat2(Mat2 mat){
    printf("0:[%f] 1:[%f] 2:[%f] 3:[%f]\n",mat.m[0],mat.m[1],mat.m[2],mat.m[3]);
  }

  Vec2 ScalateVec2(Vec2 vec, float size){
    // float modulo = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    // Vector2 aux = {(vec.x/modulo) * size, (vec.y/modulo) * size};
    // return aux;
    // printf("Original:\n");
    // DebugVector2(vec);
    
    Vec2 aux = Vec2Normalize(vec);
    aux.x = aux.x * size;
    aux.y = aux.y * size;
    return aux;
  }

  Mat3 Mat32x2Solver(Mat3 mat1,Mat3 mat2){
    bool incompatible = false;
    float x,y,z;

    //Primer despeje
    Mat3 aux1 = {(mat2.x * mat1.x),(mat2.x * mat1.y),(mat2.x * mat1.z)};
    Mat3 aux2 = {((-1 * mat1.x) * mat2.x),((-1 * mat1.x) * mat2.y),((-1 * mat1.x) * mat2.z)};

    //La X vale 0, por lo que ya tenemos la y
    float dividendo1 = (aux1.z + aux2.z); 
    float dividendo2 = (aux1.y + aux2.y);

    if(dividendo1 != 0 && dividendo2 !=0){
      y = dividendo1 / dividendo2;
    }else{
      incompatible = true;
      y = 0;
    }

    //Segundo despeje
    Mat3 matAux = {0,(aux1.y + aux2.y),(aux1.z + aux2.z)};
    Mat3 aux3 = {(matAux.y * mat2.x),(matAux.y * mat2.y),(matAux.y * mat2.z)};
    Mat3 aux4 = {(-mat2.y * matAux.x),(-mat2.y * matAux.y),(-mat2.y * matAux.z)};
    //La Y vale 0 por lo que ya tenemos la X

    dividendo1 = (aux3.z + aux4.z); 
    dividendo2 = (aux3.x+aux4.x); 

    if(dividendo1 != 0 && dividendo2 !=0){
      x = dividendo1 / dividendo2;
    }else{
      incompatible = true;
      x = 0;
    }
    // printf("X %f Y %f\n",x,y);
    if(incompatible){
      //printf("Sistema incompatible");
    }
    Mat3 resolved = {x,y,0};
    return resolved;
    
  };

  Mat3 Mat32x2Solver(Mat3 mat1,Mat3 mat2,Mat3 mat3){
    float x,y,z;

    //Primer despeje
    Mat3 aux1 = {(mat2.x * mat1.x),(mat2.x * mat1.y),(mat2.x * mat1.z)};
    Mat3 aux2 = {((-1 * mat1.x) * mat2.x),((-1 * mat1.x) * mat2.y),((-1 * mat1.x) * mat2.z)};

    //La X vale 0, por lo que ya tenemos la y
    y = (aux1.z + aux2.z) / (aux1.y + aux2.y);

    //Segundo despeje
    Mat3 matAux = {0,(aux1.y + aux2.y),(aux1.z + aux2.z)};
    Mat3 aux3 = {(matAux.y * mat2.x),(matAux.y * mat2.y),(matAux.y * mat2.z)};
    Mat3 aux4 = {(-mat2.y * matAux.x),(-mat2.y * matAux.y),(-mat2.y * matAux.z)};
    //La Y vale 0 por lo que ya tenemos la X

    x = (aux3.z + aux4.z) / (aux3.x+aux4.x);

    // printf("Y %f X %f\n",y,x);
    Mat3 resolved = {x,y,0};
    return resolved;
    
  }


  Mat3x3 Mat3Identity(){
    Mat3x3 mat ={1,0,0,
                 0,1,0,
                 0,0,1};
    return mat;
  }
