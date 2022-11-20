#include <xemath/math.h>
#include <stdio.h>
#include <math.h>

struct Vec2{
  float x,y;
};
struct Vec3{
  float x,y,z;
};

struct Mat3{
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
  Vec2 ScalateVec2(Vec2 vec, float size){
    
    Vec2 aux = Vec2Normalize(vec);
    aux.x = aux.x * size;
    aux.y = aux.y * size;
    return aux;
  }

  
  Mat3 Mat3Identity(){
    Mat3 mat ={1,0,0,
               0,1,0,
               0,0,1};
               
    return mat;
  }

  inline Mat3 Mat3Scale(Vec2 v){
    Mat3 identity = Mat3Identity();
    identity.p[0] = v.x;
    identity.p[4] = v.y;
    return identity;
  }

  inline Mat3 Mat3Rotate(float v){
    Mat3 identity = Mat3Identity();
    identity.p[0] = cosf(v);
    identity.p[1] = sinf(v);
    identity.p[3] = sin(v) * -1.0f;
    identity.p[4] = cosf(v);
  }

  inline Mat3 Mat3Translate(Vec2 v){
    Mat3 identity = Mat3Identity();
    identity.p[2] = v.x;
    identity.p[5] = v.y;

    return identity;
  }

  float Vec3Dotproduct(Vec3 v1, Vec3 v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
  }

  Mat3 Mat3MultMat3(Mat3 m1, Mat3 m2){
    //Filas * Columnas
    Mat3 result;
    Vec3 fila,columna;

    // Primera posicion
    fila.x = m1.p[0]; fila.y = m1.p[1]; fila.z = m1.p[2];
    columna.x = m1.p[0];columna.x = m1.p[3]; columna.x = m1.p[6];
    result.p[0] = Vec3Dotproduct(fila,columna);
    
    //Segunda posicion
    columna.x = m1.p[1];columna.x = m1.p[4]; columna.x = m1.p[7];
    result.p[1] = Vec3Dotproduct(fila,columna);
    
    //Tercera posicion
    columna.x = m1.p[2];columna.x = m1.p[5]; columna.x = m1.p[8];
    result.p[2] = Vec3Dotproduct(fila,columna);

    //Cuarta posicion
    fila.x = m1.p[3]; fila.y = m1.p[4]; fila.z = m1.p[5];
    columna.x = m1.p[0];columna.x = m1.p[3]; columna.x = m1.p[6];
    result.p[0] = Vec3Dotproduct(fila,columna);
    
    //Quinta posicion
    columna.x = m1.p[1];columna.x = m1.p[4]; columna.x = m1.p[7];
    result.p[1] = Vec3Dotproduct(fila,columna);
    
    //Sexta posicion
    columna.x = m1.p[2];columna.x = m1.p[5]; columna.x = m1.p[8];
    result.p[2] = Vec3Dotproduct(fila,columna);

    //Septima posicion
    fila.x = m1.p[6]; fila.y = m1.p[7]; fila.z = m1.p[8];
    columna.x = m1.p[0];columna.x = m1.p[3]; columna.x = m1.p[6];
    result.p[0] = Vec3Dotproduct(fila,columna);
    
    //Octava posicion
    columna.x = m1.p[1];columna.x = m1.p[4]; columna.x = m1.p[7];
    result.p[1] = Vec3Dotproduct(fila,columna);
    
    //Novena posicion
    columna.x = m1.p[2];columna.x = m1.p[5]; columna.x = m1.p[8];
    result.p[2] = Vec3Dotproduct(fila,columna);

    return result;
  }



  /*Mat3 Mat32x2Solver(Mat3 mat1,Mat3 mat2){
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
    
  }*/


