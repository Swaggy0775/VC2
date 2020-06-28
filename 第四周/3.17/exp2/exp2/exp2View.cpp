
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
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp2View 构造/析构

Cexp2View::Cexp2View()
{
	// TODO: 在此处添加构造代码

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
	pDC->Rectangle(pDoc->cr);
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


void Cexp2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp2Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);//需要客户区矩形信息 因为图形移动要在客户区内
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->cr.left - 50> clientRec.left)
		{
			pDoc->cr.left -= 50;
			pDoc->cr.right -= 50;
		}
		else
		{
			pDoc->cr.right -= pDoc->cr.left;
			pDoc->cr.left = 0;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right + 50 < clientRec.right)
		{
			pDoc->cr.left += 50;
			pDoc->cr.right += 50;
		}
		else
		{
			pDoc->cr.left += clientRec.right - pDoc->cr.right;
			pDoc->cr.right = clientRec.right;
		}
		break;
	case VK_UP:
		if (pDoc->cr.top-50>clientRec.top)
		{
			pDoc->cr.bottom -= 50;
			pDoc->cr.top -= 50;
		}
		else
		{
			pDoc->cr.bottom -= pDoc->cr.top - clientRec.top;
			pDoc->cr.top = 0;
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom + 50<clientRec.bottom)
		{
			pDoc->cr.bottom += 50;
			pDoc->cr.top += 50;
		}
		else
		{
			pDoc->cr.top -= pDoc->cr.bottom - clientRec.bottom;
			pDoc->cr.bottom = clientRec.bottom;
		}
		break;
	case VK_HOME:
		if((pDoc->cr.bottom!= pDoc->cr.top) &&(pDoc->cr.left!=pDoc->cr.right))
		{
			pDoc->cr.left -=50;
			pDoc->cr.top -=50;
		}
		break;

	case VK_END:
		if ((pDoc->cr.bottom != pDoc->cr.top) && (pDoc->cr.left != pDoc->cr.right))
		{
			pDoc->cr.left += 50;
			pDoc->cr.top += 50;
		}
		break;
	}

	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Cexp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp2Doc* pDoc = GetDocument();
	pDoc->cr = pDoc->cr2;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
