// SqlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp2.h"
#include "SqlDlg.h"
#include "afxdialogex.h"


// SqlDlg �Ի���

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


// SqlDlg ��Ϣ�������


void SqlDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
}
