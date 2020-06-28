#pragma once


// SqlDlg 对话框

class SqlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SqlDlg)

public:
	SqlDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SqlDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Command;
	afx_msg void OnBnClickedButton1();
};
