#ifndef QUATERNION_H_
#define QUATERNION_H_

//==============
// Definitions
//==============

/**
 * @brief Quaternions represent both a rotation axis and an angle of 
 * rotation. They represent rotations in 3D space on a 4d hypersphere
 *
 * Quaternions consist of four components: quaternion = w + xi + yj + zk. 
 * A quaternion, is more compact (4 values instead of 9), and they are 
 * more computationally efficient, especially when interpolating between 
 * rotations. Where:
 * -  w is the scalar part, which relates the axis of rotation.
 * - {x, y, z} define a 3D vector, which acts as the axis of rotation.
 * They are in a way, another way to describe motion on a coordinate system.
 * Specifically, they describe rotation on a sphere.
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
