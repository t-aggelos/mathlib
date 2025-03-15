#include <math.h>

#include "matrix.h"
#include "vector.h"
#include "quaternion.h"

/**
 * Initializes a matrix, given a pointer, by a value of k.
 * functio m4x4f_populate
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
 * Initializes the given 4x4 matrix as an identity matrix. Taking a pointer, 
 * This function directly sets the values to minimize overhead.
 * Additionally, an identity matrix is structured as:
 * - index 0-3:	  [1, 0, 0, 0]
 * - index 4-7:	  [0, 1, 0, 0]
 * - index 8-11:  [0, 0, 1, 0]
 * - index 12-15: [0, 0, 0, 1]
 * function: m4x4f_identity
 * @param ptr pointer to the m4x4f object
 * @return void
 */
void m4x4f_identity(M4x4f* m)
{
	m->data[0] = 1; m->data[1] = 0; m->data[2] = 0; m->data[3] = 0;
	m->data[4] = 0; m->data[5] = 1; m->data[6] = 0; m->data[7] = 0;
	m->data[8] = 0; m->data[9] = 0; m->data[10]= 1; m->data[11]= 0;
	m->data[12]= 0; m->data[13]= 0; m->data[14]= 0; m->data[15]= 1;
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
void m4x4f_rotate(M4x4f* out, const M4x4f* target, float angle, Vec3f* vec) 
{	
	// extract vector coordinates 
	float x = vec->x;
	float y = vec->y;
	float z = vec->z;
	
	// get the length of the vector
	float len = sqrt(x*x + y*y + z*z);
	
	// Normalize the vector (and avoid by 0 division)
	if (len > 0.0f) {
		x /= len;
		y /= len;
		z /= len;
	}
	
	// common terms & coefficients
	float coseff = cos(angle);
	float sineff = sin(angle);
	float onemincos = 1 - coseff;
	
	// first row of the rotation matrix corresponds
	// to the rotation of the point around the x-axis
	out->data[0] = coseff + x * x * onemincos;
	out->data[1] = x * y * onemincos - z * sineff;
	out->data[2] = x * z * onemincos + y * sineff;
	out->data[3] = 0;

	// second row of the rotation matrix, corresponds
	// to the rotation of the point around the y axis
	out->data[4] = y * x * onemincos + z * sineff;
	out->data[5] = coseff + y * y * onemincos;
	out->data[6] = y * z * onemincos - x * sineff;
	out->data[7] = 0;

	// likewise, corresponds to the z-axis
	out->data[8]  = z * x * onemincos - y * sineff;
	out->data[9]  = z * y * onemincos + x * sineff;
	out->data[10] = coseff + z * z * onemincos;
	out->data[11] = 0;
	
	// last row is defined as such to maintain homogeneous
	// coordinates; all matrices used in graphics do not 
	// distort their lines after a transform (preserving parallelism)
	out->data[12] = 0;
	out->data[13] = 0;
	out->data[14] = 0;
	out->data[15] = 1;

	// Multiply out with the target matrix add the rotation
	m4x4f_multiply(out, out, target);
}   

/*
	Executes an affine transform to a world matrix,
	with a rotation quaternion, a position vector and a scale vector
	note: quaternions are always [ w, x, y, z ]
*/

//@todo
void m4x4f_from_quat_scalars(
M4x4f* mat, 
Quat *quat, 
const Vec3f *position, 
const Vec3f *scale)
{

}

float m4x4f_at(M4x4f* m, unsigned char i, unsigned char j)
{
	return m->data[i * 4 + j];
}

