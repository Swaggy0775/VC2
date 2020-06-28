
// exp3View.cpp : Cexp3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp3.h"
#endif

#include "exp3Doc.h"
#include "exp3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp3View

IMPLEMENT_DYNCREATE(Cexp3View, CView)

BEGIN_MESSAGE_MAP(Cexp3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Cexp3View 构造/析构
Cexp3View::Cexp3View()
{
	// TODO: 在此处添加构造代码
}

Cexp3View::~Cexp3View()
{
}

BOOL Cexp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp3View 绘制

void Cexp3View::OnDraw(CDC* pDC)
{
	Cexp3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
		CRect clientCr;
		GetClientRect(&clientCr);
	if (!set)
	{
		cr = CRect(0, clientCr.bottom / 2 - r, 2 * r, clientCr.bottom / 2 + r);
	}

	if (cr.bottom<clientCr.bottom/2)
	{
		cr.top = clientCr.bottom/2 - r;
		cr.bottom = clientCr.bottom / 2 + r;
	}

	// TODO: 在此处为本机数据添加绘制代码
	
	pDC->Ellipse(cr);
}


// Cexp3View 打印

BOOL Cexp3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp3View 诊断

#ifdef _DEBUG
void Cexp3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp3Doc* Cexp3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp3Doc)));
	return (Cexp3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp3View 消息处理程序


//void Cexp3View::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CView::OnLButtonUp(nFlags, point);
//}


void Cexp3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CRect clientCr;
	GetClientRect(&clientCr);


	if (set2 == false)
	{
		cr.right += 20;
		cr.left += 20;

		if (cr.right > clientCr.right) set2 = true;
	}//向右



	if (set2 == true)
	{
		cr.left -= 20;
		cr.right -= 20;
		if (cr.left < clientCr.left)set2 = false;
	}//向左
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void Cexp3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetTimer(0, 50, NULL);
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(0);
	CView::OnLButtonDblClk(nFlags, point);
}
