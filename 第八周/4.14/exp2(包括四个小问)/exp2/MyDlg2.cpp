// MyDlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "exp2.h"
#include "MyDlg2.h"
#include "afxdialogex.h"

// MyDlg2 对话框

IMPLEMENT_DYNAMIC(MyDlg2, CDialogEx)

MyDlg2::MyDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

MyDlg2::~MyDlg2()
{
}

void MyDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
}


BEGIN_MESSAGE_MAP(MyDlg2, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg2::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg2 消息处理程序


void MyDlg2::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	color = RGB(a, b, c);
}
