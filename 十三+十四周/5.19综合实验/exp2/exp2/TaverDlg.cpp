// TaverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp2.h"
#include "TaverDlg.h"
#include "afxdialogex.h"


// TaverDlg �Ի���

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


// TaverDlg ��Ϣ�������


BOOL TaverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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

			s += temp;//��s���ֶ�
			 
			if(i==2)s+= _T("                 "); 
		}

		Lbox.AddString(s);
		m_DlgpSet->MoveNext();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
