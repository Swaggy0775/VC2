// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "exp1.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, c(_T(""))
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	//  DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Control(pDX, IDC_COMBO1, Cbox);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON6, &MyDlg1::OnBnClickedButton6)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序



BOOL MyDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Cbox.AddString(_T("+"));
	Cbox.AddString(_T("-"));
	Cbox.AddString(_T("*"));
	Cbox.AddString(_T("/"));
	Cbox.AddString(_T("A的倒数"));
	Cbox.AddString(_T("A开平方"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void MyDlg1::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString strCBText;
	Cbox.GetLBText(Cbox.GetCurSel(), strCBText);
	if (strCBText=='+')
	{
		c.Format(_T("%d"), a + b);
	}
	else if (strCBText == '-')
	{
		c.Format(_T("%d"), a - b);
	}
	else if (strCBText == '*')
	{
		c.Format(_T("%d"), a * b);
	}

	else if (strCBText == '/')
	{
		if (b)
			c.Format(_T("%0.6f"), 1.0*a / b);
		else
			c.Format(_T("不合法"));
	}

	else if (strCBText == "A的倒数")
	{
		if (a)
		{
			c.Format(_T("%0.6f"), 1.0 / a );
		}
		else
			c.Format(_T("不合法"));
	}
	else if (strCBText == "A开平方")
	{
		if (a>=0)
		{
			c.Format(_T("%0.6f"), sqrt(a));
		}
		else
			c.Format(_T("不合法"));
	}
	UpdateData(false);
}
