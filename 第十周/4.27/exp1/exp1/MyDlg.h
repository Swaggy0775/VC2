#pragma once
#include "afxwin.h"


// MyDlg 对话框

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	CEdit edit;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnDblclkList1();
	CString s;
	afx_msg void OnBnClickedButton1();
	int nSel;
//	afx_msg void OnClose();
};
