
// 3.9exp1.h : 3.9exp1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy39exp1App:
// �йش����ʵ�֣������ 3.9exp1.cpp
//

class CMy39exp1App : public CWinAppEx
{
public:
	CMy39exp1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy39exp1App theApp;
