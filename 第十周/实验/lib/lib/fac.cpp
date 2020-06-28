#include "stdafx.h"
#include "fac.h"
#define pi 3.1415926
int factorial(int n)
{
	if (n == 1 || n == 0)return 1;
	else
		return n*factorial(n-1);
}

float FAC::convert(float edg)
{
	float ratio =pi/180;
	return edg*ratio;
}