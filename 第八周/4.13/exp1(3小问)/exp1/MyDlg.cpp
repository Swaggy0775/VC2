// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "exp1Doc.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_Control(pDX, IDC_EDIT1, Cedit);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &MyDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}







BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Lbox.AddString(fileName);
	Lbox.AddString(_T("列表框"));


	Cedit.SetWindowTextW(fileName);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
