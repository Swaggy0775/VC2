#pragma once
#include "afxwin.h"
#include "exp1Doc.h"
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
	
	
public :
    Cexp1Doc *pDoc;
	CListBox Lcon;
	CEdit edit;
	virtual BOOL OnInitDialog();
	CString s;
	afx_msg void OnBnClickedButton1();
	int index=-1;
	int sum = 0;
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnClose();
	virtual void OnOK();
	
	CListBox Lbox;
	afx_msg void OnLbnSelchangeList5();
	afx_msg void OnLbnDblclkList5();
};
