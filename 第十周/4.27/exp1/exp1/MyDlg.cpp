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

// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
	, nSel(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_LBIndex(pDX, IDC_LIST1, nSel);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_LBN_DBLCLK(IDC_LIST1, &MyDlg::OnLbnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString filename = _T("C:\\Users\\Coisini\\Desktop\\学生名单.txt");
	ifstream ifs(filename);//与txt关联

	string s;int n;

	while (ifs >>s>>n)
	{
	CString ss=CString(s.c_str());//ss先取得姓名
	ss.Format(_T("%s %d"), ss, n);
	Lbox.AddString(ss);
	}


	//Lbox.AddString(filename);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MyDlg::OnLbnDblclkList1()
{
	// TODO: 在此添加控件通知处理程序代码
	nSel =Lbox.GetCurSel();

	if (nSel >= 0) {
		Lbox.GetText(nSel,s);
		edit.SetWindowTextW(s);
	}
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);//更新了s
	Lbox.DeleteString(nSel);
	Lbox.InsertString(nSel,s);
	UpdateData(false);
}

