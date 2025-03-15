#ifndef MATHLIB_H_
#define MATHLIB_H_

/*
	Date: March 13th 2025
	Author: t_aggelos

	Ported from JS to C.
*/
#define MATHLIB_VERSION "0.0.3"
#define MATHLIB_EPSILON 1e-6f  // Small value to handle precision issues

//===================================
//IMPORTING THE REST OF THE LIBRARIES
//===================================
#include "matrix.h"
#include "vector.h"
#include "quaternion.h"


//======================
// Forward declarations
//======================

//=======================
// Function declarations
//=======================
float deg_to_radian(float degree);
float rad_to_radian(float degree);
void normalize_radian(float *radian);

#endif  // MATHLIB_H_