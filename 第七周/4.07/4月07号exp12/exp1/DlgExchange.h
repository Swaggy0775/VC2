#pragma once


// DlgExchange �Ի���

class DlgExchange : public CDialogEx
{
	DECLARE_DYNAMIC(DlgExchange)

public:
	DlgExchange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgExchange();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString s1;
	CString s2;
	afx_msg void OnBnClickedButtonExchange();
//	afx_msg void insertS1();
};
