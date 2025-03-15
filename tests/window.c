#include "../src/mathlib.h"
#include <stdio.h>

int main()
{
	printf("RUNNING MATHLIB_VERSION: '%s'\nTesting matrices:\t", MATHLIB_VERSION);
	// testing matrices	
	M4x4f mat;

	// run init function
	m4x4f_init(&mat, 1.0f);

	// attempt to make mat into an identity matrix
	m4x4f_identity(&mat);
	printf("Success!\n\nTesting Vectors:\t");

	// vector stuff
	Vec3f vec1, vec2;
	vec1.x = 3.0f; vec1.y = 1.0f; vec1.z = 1.0f;
	vec2.x = 1.0f; vec2.y = 4.0f; vec2.z = 5.0f;
	
	// now, add the two vectors
	
	// store, vector_a, vector_b
	vec3f_add(&vec1, &vec1, &vec2);

	printf("Success!\n\n");
	return 0;
}