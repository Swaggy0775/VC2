// SqlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp2.h"
#include "SqlDlg.h"
#include "afxdialogex.h"


// SqlDlg 对话框

IMPLEMENT_DYNAMIC(SqlDlg, CDialogEx)

SqlDlg::SqlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, Command(_T(""))
{

}

SqlDlg::~SqlDlg()
{
}

void SqlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Command);
}


BEGIN_MESSAGE_MAP(SqlDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SqlDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// SqlDlg 消息处理程序


void SqlDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
}
