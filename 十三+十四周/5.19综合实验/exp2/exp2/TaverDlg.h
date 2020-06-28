#pragma once
#include "afxwin.h"


// TaverDlg 对话框

class TaverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TaverDlg)

public:
	TaverDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TaverDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	CRecordset *m_DlgpSet;
	virtual BOOL OnInitDialog();
};
