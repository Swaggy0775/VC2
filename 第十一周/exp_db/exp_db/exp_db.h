
// exp_db.h : exp_db Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cexp_dbApp:
// �йش����ʵ�֣������ exp_db.cpp
//

class Cexp_dbApp : public CWinAppEx
{
public:
	Cexp_dbApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp_dbApp theApp;
