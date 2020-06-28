// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp4.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
	, x(700)
	, s2(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Text(pDX, IDC_EDIT2, x);
	DDX_Text(pDX, IDC_EDIT3, s2);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	if (s1 == ""&&s2=="")
	{
		s1 = _T("abc");
		s2 = _T("defg");
		//x = 700;
		CString temp;
		temp.Format(_T("%d"), x);
		s2 = s1 + temp;
	}
	else
	{
		CString temp;
		temp.Format(_T("%d"), x);
		s2 = s1 + temp;
	}
	UpdateData(false);
}
