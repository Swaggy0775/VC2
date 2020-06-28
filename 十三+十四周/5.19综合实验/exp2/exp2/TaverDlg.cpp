// TaverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp2.h"
#include "TaverDlg.h"
#include "afxdialogex.h"


// TaverDlg 对话框

IMPLEMENT_DYNAMIC(TaverDlg, CDialogEx)

TaverDlg::TaverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

TaverDlg::~TaverDlg()
{
}

void TaverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
}


BEGIN_MESSAGE_MAP(TaverDlg, CDialogEx)
END_MESSAGE_MAP()


// TaverDlg 消息处理程序


BOOL TaverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Lbox.ResetContent();
	CString s;
	int n = m_DlgpSet->GetODBCFieldCount();
	m_DlgpSet->MoveFirst();
	while (!m_DlgpSet->IsEOF())
	{
		s.Empty();

		for (int i = 0; i < n; i++)
		{
			CString temp;
			m_DlgpSet->GetFieldValue((short)i, temp);

			for (int i = temp.GetLength(); i < 10; i++)
				temp += _T(" ");

			s += temp;//往s加字段
			 
			if(i==2)s+= _T("                 "); 
		}

		Lbox.AddString(s);
		m_DlgpSet->MoveNext();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
