// MyDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp2.h"
#include "MyDlg1.h"
#include "afxdialogex.h"
#include "MyDlg2.h"

// MyDlg1 �Ի���

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x0(0)
	, y0(0)
	, a(0)
	, b(0)

{

}

MyDlg1::~MyDlg1()
{

}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, x0);
	DDX_Text(pDX, IDC_EDIT2, y0);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Text(pDX, IDC_EDIT4, b);
	DDX_Text(pDX, IDC_EDIT1, x0);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg1::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg1 ��Ϣ�������




void MyDlg1::getClientDC(CDC* pDC)
{
	this->pDC = pDC;
}



void MyDlg1::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	crs[n]=CRect(x0 - b, y0 - a, x0 + b, y0 + a);
	n++;
}


BOOL MyDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	for (int i = 0; i < 10; i++)
	{
		CRect cr;
		crs.Add(cr);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
