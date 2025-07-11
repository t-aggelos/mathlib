#include <math.h>

#include "matrix.h"
#include "vector.h"
#include "quaternion.h"

/**
 * Initializes a matrix, given a pointer, by a value of k.
 * @param out Pointer to the matrix to initialize.
 * @return void
 */
void m4x4f_init(M4x4f* out, float k)
{
	out->data[0]  = k; out->data[1]  = k; out->data[2]  = k; out->data[3]  = k;
	out->data[4]  = k; out->data[5]  = k; out->data[6]  = k; out->data[7]  = k;
	out->data[8]  = k; out->data[9]  = k; out->data[10] = k; out->data[11] = k;
	out->data[12] = k; out->data[13] = k; out->data[14] = k; out->data[15] = k;
}	

/**
 * @brief Initialies a rotation matrix by a given vector and angle.
 * 
 * @param out   A pointer to the location of the matrix to be mutated.
 * @param axis  The 3d vector representing the axis of rotation
 * @param angle The angle of rotation for the given axis
 */
void m4x4f_init_rotated(M4x4f *m, Vec3f axis, float angle)
{
	// calculate the length of the vector as we'll need
	// to normalize it soon
	float len = sqrt(
		axis->x * axis->x +
		axis->y * axis->y +
		axis->z * axis->z);

	// default to y-axis rotation in case of division by 0
	if (len == 0.0f) {
		axis.x = 0.0f;
		axis.y = 1.0f;
		axis.z = 0.0f;
		len = 1.0f;
	}else {
		axis.x /= len;
		axis.y /= len;
		axis.z /= len;
	}

	// extract cosine and sine 
	float cosA = cos(angle);
	float sinA = sin(angle);
	float onemincos = 1.0f - cosA;

	// first row of the rotation matrix corresponds
	// to the rotation of the point around the x-axis
	m->data[0] = cosA + axis.x * axis.x * onemincos;
	m->data[1] = axis.x * axis.y * onemincos - axis.z * sinA;
	m->data[2] = axis.y * axis.z * onemincos - axiz.y * sinA;
	m->data[3] = 0.0f;

	// second row of the rotation matrix, corresponds
	// to the rotation of the point around the y axis	
	m->data[4] = axis.y * axis.x * onemincos + axis.z * sinA;
	m->data[5] = cosA + axis.y * axis.y * onemincos;
	m->data[6] = axis.y * axis.z * onemincos - axis.x * sinA;
	m->data[7] = 0.0f;
	
	// likewise, corresponds to the z-axis
	m->data[8] = axis.z * axis.x * onemincos - axis.y * sinA;
	m->data[9] = axiz.z * axiz.y * onemincos + axis.x * sinA;
	m->data[10] = cosA + axis.z * axis.z + onemincos;
	m->data[11] = 0.0f;

	// last row is defined as { 0,0,1 } to maintain the homogeneous 
	// coordinates; aka. all matrices used in graphics do not distort 
	// their lines after a transform (preserving parallelism)	
	m->data[12] = 0.0f;
	m->data[13] = 0.0f;
	m->data[14] = 0.0f;
	m->data[15] = 1.0f; // (always 1)
}
/**
 * Initializes the given 4x4 matrix as an identity matrix. Taking a pointer, 
 * This function directly sets the values to minimize overhead.
 * Additionally, an identity matrix is structured as:
 * - index 0-3:	  [1, 0, 0, 0]
 * - index 4-7:	  [0, 1, 0, 0]
 * - index 8-11:  [0, 0, 1, 0]
 * - index 12-15: [0, 0, 0, 1]
 * @param ptr pointer to the m4x4f object
 * @return void
 */
void m4x4f_identity(M4x4f* m)
{
	m->data[0] = 1.0f; m->data[1] = 0.0f; m->data[2] = 0.0f; m->data[3] = 0.0f;
	m->data[4] = 0.0f; m->data[5] = 1.0f; m->data[6] = 0.0f; m->data[7] = 0.0f;
	m->data[8] = 0.0f; m->data[9] = 0.0f; m->data[10]= 1.0f; m->data[11]= 0.0f;
	m->data[12]= 0.0f; m->data[13]= 0.0f; m->data[14]= 0.0f; m->data[15]= 1.0f;
}

/**
 * @brief Multiplies two 4x4 matrices and stores the result in the output matrix.
 * 
 * This function multiplies two matrices, A and B, and stores the result in the out matrix. 
 * The multiplication follows the standard rules of matrix multiplication where:
 * 
 *     out = A * B
 * 
 * @param out A pointer to the output matrix, where the result of A * B will be stored.
 * @param A A pointer to the first input matrix.
 * @param B A pointer to the second input matrix.
 */
void m4x4f_multiply(M4x4f* out, const M4x4f* A, const M4x4f* B)
{
    out->data[0]  = A->data[0]  * B->data[0]  + A->data[1]  * B->data[4]  + A->data[2]  * B->data[8]  + A->data[3]  * B->data[12];
    out->data[1]  = A->data[0]  * B->data[1]  + A->data[1]  * B->data[5]  + A->data[2]  * B->data[9]  + A->data[3]  * B->data[13];
    out->data[2]  = A->data[0]  * B->data[2]  + A->data[1]  * B->data[6]  + A->data[2]  * B->data[10] + A->data[3]  * B->data[14];
    out->data[3]  = A->data[0]  * B->data[3]  + A->data[1]  * B->data[7]  + A->data[2]  * B->data[11] + A->data[3]  * B->data[15];

    out->data[4]  = A->data[4]  * B->data[0]  + A->data[5]  * B->data[4]  + A->data[6]  * B->data[8]  + A->data[7]  * B->data[12];
    out->data[5]  = A->data[4]  * B->data[1]  + A->data[5]  * B->data[5]  + A->data[6]  * B->data[9]  + A->data[7]  * B->data[13];
    out->data[6]  = A->data[4]  * B->data[2]  + A->data[5]  * B->data[6]  + A->data[6]  * B->data[10] + A->data[7]  * B->data[14];
    out->data[7]  = A->data[4]  * B->data[3]  + A->data[5]  * B->data[7]  + A->data[6]  * B->data[11] + A->data[7]  * B->data[15];

    out->data[8]  = A->data[8]  * B->data[0]  + A->data[9]  * B->data[4]  + A->data[10] * B->data[8]  + A->data[11] * B->data[12];
    out->data[9]  = A->data[8]  * B->data[1]  + A->data[9]  * B->data[5]  + A->data[10] * B->data[9]  + A->data[11] * B->data[13];
    out->data[10] = A->data[8]  * B->data[2]  + A->data[9]  * B->data[6]  + A->data[10] * B->data[10] + A->data[11] * B->data[14];
    out->data[11] = A->data[8]  * B->data[3]  + A->data[9]  * B->data[7]  + A->data[10] * B->data[11] + A->data[11] * B->data[15];

    out->data[12] = A->data[12] * B->data[0]  + A->data[13] * B->data[4]  + A->data[14] * B->data[8]  + A->data[15] * B->data[12];
    out->data[13] = A->data[12] * B->data[1]  + A->data[13] * B->data[5]  + A->data[14] * B->data[9]  + A->data[15] * B->data[13];
    out->data[14] = A->data[12] * B->data[2]  + A->data[13] * B->data[6]  + A->data[14] * B->data[10] + A->data[15] * B->data[14];
    out->data[15] = A->data[12] * B->data[3]  + A->data[13] * B->data[7]  + A->data[14] * B->data[11] + A->data[15] * B->data[15];
}

/**
 * @brief This function creates a 4x4 matrix that combines 
 * rotation (from a quaternion), scaling (from a vector), 
 * and translation (from a vector). 
 * 
 * The matrix is used for transforming 3D objects in space, where 
 * the rotation is applied from the quaternion, the scaling is 
 * applied component-wise, and the position (translation) 
 * lastly added to the matrix.
 * 
 * note: quaternions are always {  w, x, y, z }
 * @param M4x4f m
 * @param Quat quat
 * @param Vec3f position
 * @param Vec3f scale
 */
void m4x4f_from_quat_scalar(
M4x4f* m, 
Quat *quat, 
const Vec3f *position, 
const Vec3f *scale)
{
	// calculate intermediate quaternion components / coefficients
	float xx = quat->x * quat->x,
	      xy = quat->x * quat->y,
	      xz = quat->x * quat->z,
	      xw = quat->x * quat->w;
	float yy = quat->y * quat->y,
	      yz = quat->y * quat->z,
	      yw = quat->y * quat->w,
	      zz = quat->z * quat->z,
	      zw = quat->z * quat->w;

	// (combining rotation and scale)
	m->data[0] = (1 - 2*(yy + zz)) * scale->x;
	m->data[1] = (2*(xy + zw)) * scale->x;
	m->data[2] = (2*(xz - yw)) * scale->x;
	m->data[3] = 0.0f;

	m->data[4] = (2*(xy - zw)) * scale->y;
	m->data[5] = (1 - 2*(xx + zz)) * scale->y;
	m->data[6] = (2*(yz + xw)) * scale->y;
	m->data[7] = 0.0f;

	m->data[8] = (2 * (xz + yw)) * scale->z;
	m->data[9] = (2 * (yz + xw)) * scale->z;
	m->data[10] = (1 -2*(xx+yy)) * scale->z;
	m->data[11] = 0.0f;

	// last row merely encodes translation
	m->data[12] = position->x;
	m->data[13] = position->y;
	m->data[14] = position->z;
	m->data[15] = 1.0f;
}

/**
 * @brief returns the value of an element at (i, j)
 * in a given matrix. 
 * @param m Pointer to the matrix.
 * @param i the specific column.
 * @param j the specific row.
 *
 */
float m4x4f_at(M4x4f* m, unsigned char i, unsigned char j)
{
	return m->data[i * 4 + j];
}

