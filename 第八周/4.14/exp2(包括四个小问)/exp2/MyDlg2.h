#pragma once


// MyDlg2 对话框

class MyDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg2)

public:
	MyDlg2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
	int c;
	int color;
//	afx_msg int OnBnClickedButton1();
	afx_msg void OnBnClickedButton1();
};
