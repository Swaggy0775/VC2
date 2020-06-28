// DlgExchange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp1.h"
#include "DlgExchange.h"
#include "afxdialogex.h"


// DlgExchange �Ի���

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


// DlgExchange ��Ϣ�������


void DlgExchange::OnBnClickedButtonExchange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	CString temp=s1;
	s1 = s2;
	s2 = temp;
	UpdateData(false);
}


