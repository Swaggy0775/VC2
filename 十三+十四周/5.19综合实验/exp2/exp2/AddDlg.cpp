// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp2.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// AddDlg 对话框

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, Name(_T(""))
	, Sno(_T(""))
	, Salary(-1)
	, Birthday(_T(""))
	, Telephone(_T(""))
	, prof(_T(""))
	, PicPath(_T(""))
	, Addre(_T(""))
{

}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Name);
	DDX_Text(pDX, IDC_EDIT2, Sno);
	DDX_Control(pDX, IDC_COMBO1, Cbox);
	DDX_Text(pDX, IDC_EDIT3, Salary);
	DDX_Text(pDX, IDC_EDIT6, Birthday);
	DDX_Text(pDX, IDC_EDIT7, Telephone);
	DDX_Text(pDX, IDC_EDIT4, prof);
	DDX_Control(pDX, IDC_COMBO2, Cbox2);
	DDX_Text(pDX, IDC_EDIT5, Addre);
}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &AddDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// AddDlg 消息处理程序


BOOL AddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//MessageBox(_T("添加记录时一定要填学号"));

	CString s;
	for (int i = 100; i>0; i--)
	{
		s.Format(_T("%d"),i);
		Cbox.AddString(s);
	}


	Cbox2.AddString(_T("男"));
	Cbox2.AddString(_T("女"));

	if (Age>=0)
		Cbox.SetCurSel(11);

	if(!Sex.IsEmpty())
	Cbox2.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}




void AddDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Age = -1;
	UpdateData(true);
	if (Cbox.GetCurSel() != -1)
	{
		Cbox.GetLBText(Cbox.GetCurSel(), AgeStr);
		Age = _ttoi(AgeStr);
	}

	if (Cbox2.GetCurSel() != -1)
	{
		Cbox2.GetLBText(Cbox2.GetCurSel(), Sex);
	}

	CDialogEx::OnOK();
}







void AddDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog cdf(true);
	int r = cdf.DoModal();
	if (r == IDOK)
	{
		PicPath = cdf.GetPathName();
	}
}

