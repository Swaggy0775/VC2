// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "string"



// MyDlg 对话框

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
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()


	//图片不能再init初始化 可以在Onpaint
	CImage img;
	img.Load(s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//获取控件的指针

	CRect rc;
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_picture为picture控件ID
	pWnd->GetClientRect(&rc);//rc为控件的大小

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
