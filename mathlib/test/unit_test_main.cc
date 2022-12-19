#include "vector_test.h"
#include "matrix_test.h"

#include <stdio.h>
#include <stdlib.h> 
#include <oxml/Mathf.h>

int main() {

	// Vectores
	UnitTest::Vec2Test();
	UnitTest::Vec3Test();
	UnitTest::Vec4Test();

	// Matrices
	UnitTest::Mat3Test();
	UnitTest::Mat4Test();


#ifdef _WIN32
	system("pause");  // windows only...
#endif

	return 0;
}


