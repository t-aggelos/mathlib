#ifndef VECTOR_H_
#define VECTOR_H_

//==============
// Definitions
//==============

typedef union Vec3f {
	struct {
		float x;
		float y;
		float z;
	};
	float data[3];
} Vec3f;


typedef union Vec3i {
	struct {
		int x;
		int y;
		int z;
	};
	int data[3];
} Vec3i;

//======================
// Forward declarations
//======================

//=======================
// Function declarations
//=======================
void vec3f_dot(float out, Vec3f *a, Vec3f *b);
void vec3f_normalize(Vec3f *v);
void vec3f_mult_scalar(Vec3f *v, float n);
void vec3f_add_scalar(Vec3f *v, float n);
void vec3f_add(Vec3f *out, Vec3f *v1, Vec3f *v2);
void vec3f_sub(Vec3f *out, Vec3f *v1, Vec3f *v2);
void vec3f_mult(Vec3f *out, Vec3f *v1, Vec3f *v2);
void vec3f_cross(Vec3f *out, Vec3f *a, Vec3f *b);
#endif // VECTOR_H_
