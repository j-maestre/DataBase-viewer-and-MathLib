#include "vector_test.h"
#include "matrix_test.h"

#include <stdio.h>
#include <stdlib.h> 
#include <oxml/Mathf.h>

int main() {

	// Vectors
	/*UnitTest::Vec2Test();
	UnitTest::Vec3Test();
	UnitTest::Vec4Test();

	// Matrices
	UnitTest::Mat3Test();
	UnitTest::Mat4Test();*/
  float number = 15.0f;
  printf("*** SQRT ***\n");
  printf("Origin-> %f\n",sqrtf(number));
  printf("Jonh carmak aberration \n");
  printf("JC-> %f",1.0f/oxml::Mathf::rsqrt(number));

#ifdef _WIN32
	system("pause");  // windows only...
#endif

	return 0;
}


