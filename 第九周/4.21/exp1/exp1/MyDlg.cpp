// MyDlg.cpp : 实现文件
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
// MyDlg 对话框

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


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化


	ifstream ifs(_T("C:\\Users\\Coisini\\Desktop\\学生名单.txt"));//与txt关联
	string name;
	int n;

	while (ifs >> name >> n)
	{
		sum++;
		CString s = CString(name.c_str());//注意txt文件需要ANSI格式才能读取
		s.Format(_T("%s %d"),s,n);
		Lcon.AddString(s);
		Lbox.AddString(s);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	index = Lcon.GetCurSel();//获得双击的串的下标
	Lcon.GetText(index,s);
	UpdateData(false);
}





void MyDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("C:\\Users\\Coisini\\Desktop\\学生名单.txt"));
	ofstream ofs(s);//流与txt文件关联

	for (int i = 0; i < sum; i++)
	{
		Lcon.GetText(i, s);
		ofs << CT2A(s.GetString()) << endl;
	}

	ofs << CT2A(_T("已修改")) << endl;
	CDialogEx::OnClose();
}


void MyDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	CString s;
	s.Format(_T("C:\\Users\\Coisini\\Desktop\\学生名单.txt"));
	ofstream ofs(s);//流与txt文件关联

	for (int i = 0; i < sum; i++)
	{
		Lcon.GetText(i, s);
		ofs << CT2A(s.GetString()) << endl;
	}

	ofs << CT2A(_T("已修改")) << endl;


	for (int i = 0; i < sum; i++)
	{
		Lcon.GetText(i, s);
		pDoc->m_str.Add(s);
	}
	CDialogEx::OnOK();
}






void MyDlg::OnLbnDblclkList5()
{
	// TODO: 在此添加控件通知处理程序代码
	index = Lbox.GetCurSel();//获得双击的串的下标
	Lbox.GetText(index, s);
	UpdateData(false);
}
