#pragma once
#include "afxwin.h"


// TaverDlg �Ի���

class TaverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TaverDlg)

public:
	TaverDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TaverDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	CRecordset *m_DlgpSet;
	virtual BOOL OnInitDialog();
};
