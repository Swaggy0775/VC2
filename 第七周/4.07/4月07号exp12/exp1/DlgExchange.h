#pragma once


// DlgExchange 对话框

class DlgExchange : public CDialogEx
{
	DECLARE_DYNAMIC(DlgExchange)

public:
	DlgExchange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgExchange();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s1;
	CString s2;
	afx_msg void OnBnClickedButtonExchange();
//	afx_msg void insertS1();
};
