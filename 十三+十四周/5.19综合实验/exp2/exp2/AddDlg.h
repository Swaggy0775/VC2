#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// AddDlg �Ի���

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString Name;
	CString Sno;
	CString AgeStr;
	int Age;
	CComboBox Cbox;
	afx_msg void OnBnClickedOk();
	long Salary;
	CString Birthday;
	CString Telephone;
	CString prof;
	CString Sex;
	CComboBox Cbox2;
	CString PicPath;
	afx_msg void OnBnClickedButton1();
	CString Addre;
};
