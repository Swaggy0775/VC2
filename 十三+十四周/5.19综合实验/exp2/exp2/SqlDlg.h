#pragma once


// SqlDlg �Ի���

class SqlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SqlDlg)

public:
	SqlDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SqlDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString Command;
	afx_msg void OnBnClickedButton1();
};
