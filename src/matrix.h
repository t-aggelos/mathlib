#ifndef MATRIX_H_
#define MATRIX_H_
//==============
// Definitions
//==============

typedef struct {
	float data[16]; // 4x4 = 16 elements
} M4x4f;

//======================
// Forward declarations
//======================

typedef union Vec3f Vec3f;
typedef union Quat Quat;

//=======================
// Function declarations
//=======================

void m4x4f_identity(M4x4f *m);
void m4x4f_mutliply(M4x4f *out, M4x4f *target);
void m4x4f_rotate(M4x4f *out, M4x4f *target, float angle, Vec3f *vec);
void m4x4f_affine_from_quat_scalars(M4x4f *mat, Quat *quat, Vec3f *position, Vec3f *scale);
void m4x4f_populate(M4x4f *out, float k);
float m4x4f_at(M4x4f *m, unsigned char i, unsigned char j);

#endif // MATRIX_H_