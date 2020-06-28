
// 4.21exp1View.cpp : CMy421exp1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.21exp1.h"
#endif

#include "4.21exp1Doc.h"
#include "4.21exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy421exp1View

IMPLEMENT_DYNCREATE(CMy421exp1View, CView)

BEGIN_MESSAGE_MAP(CMy421exp1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy421exp1View 构造/析构

CMy421exp1View::CMy421exp1View()
{
	// TODO: 在此处添加构造代码

}

CMy421exp1View::~CMy421exp1View()
{
}

BOOL CMy421exp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy421exp1View 绘制

void CMy421exp1View::OnDraw(CDC* pDC)
{
	CMy421exp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	pDC->Ellipse(cr);

}


// CMy421exp1View 打印

BOOL CMy421exp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy421exp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy421exp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy421exp1View 诊断

#ifdef _DEBUG
void CMy421exp1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy421exp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy421exp1Doc* CMy421exp1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy421exp1Doc)));
	return (CMy421exp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy421exp1View 消息处理程序


void CMy421exp1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int x0 = cr.CenterPoint().x;
	int y0 = cr.CenterPoint().y;

	int a = (cr.bottom - cr.top) / 2;
	int b = (cr.right - cr.left) / 2;
	int x = point.x-x0;
	int y = point.y-y0;

	CRgn rgn;
	rgn.CreateEllipticRgn(cr.left, cr.top, cr.right, cr.bottom);
	if (rgn.PtInRegion(point))
		GetDC()->TextOutW(20, 20, _T("Yes"));
	else
		Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
