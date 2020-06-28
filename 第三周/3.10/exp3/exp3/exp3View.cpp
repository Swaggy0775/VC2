
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
	ON_WM_LBUTTONDOWN()
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

	// TODO: 在此处为本机数据添加绘制代码

	pDC->Rectangle(cr1);
	pDC->Rectangle(cr2);
	pDC->Rectangle(cr3);
	pDC->Rectangle(cr4);
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


void Cexp3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Cexp3Doc* pDoc = GetDocument();
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	CClientDC dc(this);


	if (cr1.PtInRect(CPoint(point.x, point.y)))
	{
		pDoc->a = rand() % 50 + 5;
		s.Format(_T("a=%d"),pDoc->a);
		dc.TextOutW(cr1.CenterPoint().x, cr1.CenterPoint().y,s);
	}
	else if (cr2.PtInRect(CPoint(point.x, point.y)))
	{
		pDoc->b = rand() % 50 + 5;
		s.Format(_T("b=%d"), pDoc->b);
		dc.TextOutW(cr2.CenterPoint().x, cr2.CenterPoint().y, s);
	}
	else if (cr3.PtInRect(CPoint(point.x, point.y)))
	{
		if (count == 1)pDoc->s.Format(_T("%d"), pDoc->a + pDoc->b);
		
		dc.TextOutW(point.x,point.y,pDoc->s);
	}//cr3
	else if (cr4.PtInRect(CPoint(point.x, point.y)))
	{
		if (count == 1)
		{
			pDoc->s.Format(_T("%d"), pDoc->a + pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y, _T("+"));
		}
		else if (count == 2)
		{
			pDoc->s.Format(_T("%d"), pDoc->a - pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y +20, _T("-"));
		}
		else if (count == 3)
		{
			pDoc->s.Format(_T("%d"), pDoc->a * pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y+10, _T("*"));
		}
		else if (count == 4)
		{
			pDoc->s.Format(_T("%0.6f"),(float) pDoc->a / (float)pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y-10, _T("/"));
		}
		count++;
	}//cr4
	else
	{
		
		dc.TextOutW(point.x, point.y, _T("无效"));
	}
	CView::OnLButtonDown(nFlags, point);
}
