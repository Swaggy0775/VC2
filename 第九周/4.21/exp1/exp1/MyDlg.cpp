// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "fstream"
#include "iostream"
using namespace std;
#include "string"
#include "exp1Doc.h"
#include "MainFrm.h"
#include "exp1Doc.h"
// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
	, index(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Control(pDX, IDC_LIST1, Lcon);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_LBIndex(pDX, IDC_LIST1, index);
	DDX_Control(pDX, IDC_LIST5, Lbox);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
	ON_LBN_DBLCLK(IDC_LIST1, &MyDlg::OnLbnDblclkList1)
	ON_WM_CLOSE()
	ON_WM_CLOSE()
	ON_WM_CLOSE()
	ON_LBN_DBLCLK(IDC_LIST5, &MyDlg::OnLbnDblclkList5)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


	ifstream ifs(_T("C:\\Users\\Coisini\\Desktop\\ѧ������.txt"));//��txt����
	string name;
	int n;

	while (ifs >> name >> n)
	{
		sum++;
		CString s = CString(name.c_str());//ע��txt�ļ���ҪANSI��ʽ���ܶ�ȡ
		s.Format(_T("%s %d"),s,n);
		Lcon.AddString(s);
		Lbox.AddString(s);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	if (index != -1)
	{
		Lcon.DeleteString(index);
		Lcon.InsertString(index, s);

		Lbox.DeleteString(index);
		Lbox.InsertString(index, s);
	}
	UpdateData(false);
}


void MyDlg::OnLbnDblclkList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	index = Lcon.GetCurSel();//���˫���Ĵ����±�
	Lcon.GetText(index,s);
	UpdateData(false);
}





void MyDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	s.Format(_T("C:\\Users\\Coisini\\Desktop\\ѧ������.txt"));
	ofstream ofs(s);//����txt�ļ�����

	for (int i = 0; i < sum; i++)
	{
		Lcon.GetText(i, s);
		ofs << CT2A(s.GetString()) << endl;
	}

	ofs << CT2A(_T("���޸�")) << endl;
	CDialogEx::OnClose();
}


void MyDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	CString s;
	s.Format(_T("C:\\Users\\Coisini\\Desktop\\ѧ������.txt"));
	ofstream ofs(s);//����txt�ļ�����

	for (int i = 0; i < sum; i++)
	{
		Lcon.GetText(i, s);
		ofs << CT2A(s.GetString()) << endl;
	}

	ofs << CT2A(_T("���޸�")) << endl;


	for (int i = 0; i < sum; i++)
	{
		Lcon.GetText(i, s);
		pDoc->m_str.Add(s);
	}
	CDialogEx::OnOK();
}






void MyDlg::OnLbnDblclkList5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	index = Lbox.GetCurSel();//���˫���Ĵ����±�
	Lbox.GetText(index, s);
	UpdateData(false);
}
