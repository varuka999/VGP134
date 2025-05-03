#pragma once

namespace Math
{
	int Add(int a, int b);
	int Subtract(int a, int b);
	int Multiply(int a, int b);
	int Divide(int a, int b);
}

#define MATH_MIN(a, b) ((a < b) ? a : b)
#define MATH_MAX(a, b) ((a > b) ? a : b)
//#define MATH_CLAMP(a, min, max) ((((a < min) ? min : a) > max) ? max : a)
#define MATH_CLAMP(a, min, max) ((a < min) ? min : ((a > max) ? max : a))
#define MATH_ABS(a) (((a) < 0) ? -(a) : (a))
