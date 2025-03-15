#ifndef QUATERNION_H_
#define QUATERNION_H_

//==============
// Definitions
//==============

/* 
	Quaternions represent both a rotation axis and an angle of rotation,
	as 4d complex numbers(w + xi + yj + zk). During rotations, we want
	the three axes to be rotating independent of each other. Quaternions,
	avoid this problem(gimbal lock) by rotating axis on a 4d hypersphere
*/

typedef union Quat {
	struct {
		float x;
		float y;
		float z;
		float w;
	};
	float data[4];
} Quat;



//======================
// Forward declarations
//======================

typedef union Vec3f Vec3f;

//=======================
// Function declarations
//=======================

void quat_identity(Quat *quat);
void set_axis_angle(Quat *quat, Vec3f *vec, float rad);
void quat_multiply(Quat *out, Quat *q1, Quat *q2);
void quat_normalize(Quat *quat);

#endif // QUATERNION_H_