
// 4.21exp1.h : 4.21exp1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy421exp1App:
// �йش����ʵ�֣������ 4.21exp1.cpp
//

class CMy421exp1App : public CWinAppEx
{
public:
	CMy421exp1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy421exp1App theApp;
