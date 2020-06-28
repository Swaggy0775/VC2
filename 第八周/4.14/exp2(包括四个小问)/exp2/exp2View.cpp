
// exp2View.cpp : Cexp2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp2.h"
#endif

#include "exp2Doc.h"
#include "exp2View.h"
#include "MyDlg1.h"
#include "MyDlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cexp2View

IMPLEMENT_DYNCREATE(Cexp2View, CView)

BEGIN_MESSAGE_MAP(Cexp2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(EilipseColor, &Cexp2View::OnEilipsecolor)
	ON_COMMAND(ICreateEilipse, &Cexp2View::OnICreateeilipse)
END_MESSAGE_MAP()

// Cexp2View 构造/析构

Cexp2View::Cexp2View()
{
	// TODO: 在此处添加构造代码
	for (int i = 0; i < 50; i++)
	{
		CRect cr;
		crs.Add(cr);
	}
}

Cexp2View::~Cexp2View()
{

}

BOOL Cexp2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp2View 绘制

void Cexp2View::OnDraw(CDC* pDC)
{
	Cexp2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码

	if (vline)
	{
		CPen newpen;//根据自己需要填充颜色
		CPen *oldpen;
		newpen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
		oldpen = pDC->SelectObject(&newpen);//选新度的画刷
		pDC->Rectangle(crs[vline - 1]);
		pDC->SelectObject(oldpen);
	}
	for (int i = 0; i <= index; i++)
	{
		pDC->Ellipse(crs[i]);
	}
}


// Cexp2View 打印

BOOL Cexp2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp2View 诊断

#ifdef _DEBUG
void Cexp2View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp2Doc* Cexp2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2Doc)));
	return (Cexp2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2View 消息处理程序


void Cexp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	vline = 0;
	set = true;
	s = point;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	if (sqrt(abs((point.x - s.x)*(point.x - s.x) + (point.y - s.y)*(point.y - s.y))) < 1.0 && index>0)
	{
		for (int i = 0; i <= index; i++)
		{
			CRgn rgn;
			rgn.CreateEllipticRgn(crs[i].left, crs[i].top, crs[i].right, crs[i].bottom);
			if (rgn.PtInRegion(point))
			{ 
				vline = i+1;
				Invalidate();
				}
		}
		return;
	}
	index++;
		
	CView::OnLButtonUp(nFlags, point);
}


void Cexp2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set)
	{
		crs[index].SetRect(min(point.x,s.x), min(point.y, s.y), max(point.x, s.x), max(point.y, s.y) );
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


//void Cexp2View::OnIshoweilipse()
//{
//	// TODO: 在此添加命令处理程序代码
//}



void Cexp2View::OnEilipsecolor()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int r=dlg.DoModal();
	CDC* pDC = GetDC();
	CBrush brush(dlg.color);//根据自己需要填充颜色
	CBrush *oldbrush;

	if (r == IDOK)
	{
	oldbrush = pDC->SelectObject(&brush);//选新度的画刷

	for (int i = 0; i <= index; i++)pDC->Ellipse(crs[i]);

	pDC->SelectObject(oldbrush);//将原来的画刷选回去
	}
}





void Cexp2View::OnICreateeilipse()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		for (int i = 0; i < dlg.n; i++)
		{
			crs[index] = dlg.crs[i];
			index++;
		}
		Invalidate();
	}
}
