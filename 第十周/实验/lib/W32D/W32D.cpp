// W32D.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W32D.h"


// 这是导出变量的一个示例
W32D_API int nW32D=0;

// 这是导出函数的一个示例。
W32D_API int fnW32D(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W32D.h
CW32D::CW32D()
{
    return;
}
#define pi 3.1415926

W32D_API int Factorial(int n)
{
	if (n == 1 || n == 0)return 1;
	else
		return n*Factorial(n - 1);
}

float FACD::convert(float edg)
{
	float ratio = pi / 180;
	return edg*ratio;
}