#include "stdafx.h"
#include "w32.h"

char *pchar()
{
	return "这个串从静态库取得";
}
int F1::GetA()
{
	return a + 1;
}