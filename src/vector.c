#include <math.h>

#include "vector.h"

// computes the dot product between two vectors
void vec3f_dot(float out, Vec3f* a, Vec3f* b)
{
	out = a->x * b->x +
		   a->y * b->y +
		   a->z * b->z; 
}

// normalizes a vector (v)
void vec3f_normalize(Vec3f* v)
{
	float len = sqrt(
		v->x * v->x + 
		v->y * v->y +
		v->z * v->z
	);

	if (len > 0.0f) {
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
}

//
// Scalar operations 
//

// multiply a vector v by a float n
void vec3f_mult_scalar(Vec3f* v, float n)
{
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

// translate a vector v by a float n
void vec3f_add_scalar(Vec3f* v, float n)
{
	v->x += n;
	v->y += n;
	v->z += n;
}


//
// Vector w/ Vector Operations
//

// adds two vectors
void vec3f_add(Vec3f* out, Vec3f* v1, Vec3f* v2)
{
	out->x = v1->x + v2->x;
	out->y = v1->y + v2->y;
	out->z = v1->z + v2->z;
}

// subtracts two vectors
void vec3f_sub(Vec3f* out, Vec3f* v1, Vec3f* v2)
{
	out->x = v1->x - v2->x;
	out->y = v1->y - v2->y;
	out->z = v1->z - v2->z;
}

void vec3f_mult(Vec3f* out, Vec3f* v1, Vec3f* v2)
{
	out->x += v1->x * v2->x;
	out->y += v1->y * v2->y;
	out->z += v1->z * v2->z;
}

void vec3f_cross(Vec3f* out, Vec3f* a, Vec3f* b)
{
	out->x = a->y * b->z - a->z * b->y;
	out->y = a->z * b->x - a->x * b->z;
	out->z = a->x * b->y - a->y * b->x;
}