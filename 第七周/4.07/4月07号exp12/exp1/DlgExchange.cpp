// DlgExchange.cpp : 实现文件
//

#include "stdafx.h"
#include "exp1.h"
#include "DlgExchange.h"
#include "afxdialogex.h"


// DlgExchange 对话框

IMPLEMENT_DYNAMIC(DlgExchange, CDialogEx)

DlgExchange::DlgExchange(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, s1(_T(""))
	, s2(_T(""))
{

}

DlgExchange::~DlgExchange()
{
}

void DlgExchange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, s1);
	DDX_Text(pDX, IDC_EDIT1, s2);
}


BEGIN_MESSAGE_MAP(DlgExchange, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgExchange::OnBnClickedButtonExchange)
END_MESSAGE_MAP()


// DlgExchange 消息处理程序


void DlgExchange::OnBnClickedButtonExchange()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString temp=s1;
	s1 = s2;
	s2 = temp;
	UpdateData(false);
}


