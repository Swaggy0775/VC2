// W32D.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "W32D.h"


// ���ǵ���������һ��ʾ��
W32D_API int nW32D=0;

// ���ǵ���������һ��ʾ����
W32D_API int fnW32D(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� W32D.h
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