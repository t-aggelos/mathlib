#include <math.h>

#include "quaternion.h"
#include "vector.h"

void quat_identity(Quat* quat)
{
	quat->x = 0;
	quat->y = 0;
	quat->z = 0;
	quat->w = 1; // first value is w = cos(0) = 1
}

void quat_normalize(Quat* quat)
{
	float len = sqrt(
		quat->w * quat->w +
		quat->x * quat->x +
		quat->y * quat->y +
		quat->z * quat->z
	);
	
	if (len >0.0f) {
		quat->w /= len;
		quat->x /= len;
		quat->y /= len;
		quat->z /= len;
	}
}

// Sets the quaternion to represent a rotation around 
// an axis by an angle in radians
void set_axis_angle(Quat* quat, Vec3f *vec, float rad)
{
	rad *= 0.5f;
	int sin_half_angle = sin(rad);
	quat->w = cos(rad);
	quat->x = sin_half_angle * vec->x;
	quat->y = sin_half_angle * vec->y;
	quat->z = sin_half_angle * vec->z;
}

void quat_multiply(Quat* out, Quat* q1, Quat* q2)
{
    // reduce redundant referencing
    float w1 = q1->w, x1 = q1->x, y1 = q1->y, z1 = q1->z;
    float w2 = q2->w, x2 = q2->x, y2 = q2->y, z2 = q2->z;

    // Common terms
    float wx = w1 * x2, wy = w1 * y2, wz = w1 * z2;
    float xx = x1 * x2, xy = x1 * y2, xz = x1 * z2;
    float yy = y1 * y2, yz = y1 * z2;
    float zz = z1 * z2;

    // extract result
    out->w = w1 * w2 - xx - yy - zz;
    out->x = wx + wy + wz;
    out->y = wx - xy - yz;
    out->z = wy - xz - zz;
}
