// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "string"



// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()




void MyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()


	//ͼƬ������init��ʼ�� ������Onpaint
	CImage img;
	img.Load(s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//��ȡ�ؼ���ָ��

	CRect rc;
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_pictureΪpicture�ؼ�ID
	pWnd->GetClientRect(&rc);//rcΪ�ؼ��Ĵ�С

	int sx, sy, w, h;
	float rc_ratio = 1.0*rc.Width() / rc.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	
	if (rc_ratio >= img_ratio)
	{
		h = rc.Height();
		w = img_ratio*h;
		sx = (rc.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rc.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rc.Height() - h) / 2;
	}
	img.Draw(pDC->m_hDC,sx,sy,w,h);
}
