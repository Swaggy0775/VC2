
// exp1View.cpp : Cexp1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp1.h"
#endif

#include "exp1Doc.h"
#include "exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1View

IMPLEMENT_DYNCREATE(Cexp1View, CView)

BEGIN_MESSAGE_MAP(Cexp1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp1View 构造/析构

Cexp1View::Cexp1View()
{
	// TODO: 在此处添加构造代码

}

Cexp1View::~Cexp1View()
{
}

BOOL Cexp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp1View 绘制

void Cexp1View::OnDraw(CDC* pDC)
{
	Cexp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CSize sz = pDC->GetTextExtent(str);


	//CString n;n.Format(_T("%d"),sz.cx);

	CRect cr=CRect(200,200,500,400);
	pDC->Rectangle(cr);
	if (sz.cx > 300)
	{
		pDC->TextOutW(100, 100, _T("无法继续输入"));
		str.Delete(str.GetLength() - 1);
		pDC->TextOutW(s.x + 1, s.y + 1, str);
		set = true;
		return;
	}
	pDC->TextOutW(s.x+1, s.y+1, str);
}


// Cexp1View 打印

BOOL Cexp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp1View 诊断

#ifdef _DEBUG
void Cexp1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1Doc* Cexp1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1Doc)));
	return (Cexp1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1View 消息处理程序


void Cexp1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set == true)return;

	CClientDC dc(this);
	char ch = nChar;
	str += ch;
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Cexp1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonDown(nFlags, point);
}
