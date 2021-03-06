
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
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp3View 构造/析构

Cexp3View::Cexp3View()
{
	// TODO: 在此处添加构造代码
	for (int i = 0; i < 10; i++)
	{
		CString s;
		m_str.Add(s);
	}
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
	CRect cr = CRect(200, 200, 500, 400);
	pDC->Rectangle(cr);
	for (int i = 0; i < n+1; i++)
	{
		pDC->TextOutW(s.x+1, s.y+1 + 20 * i, m_str[i]);
	}
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


void Cexp3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	char ch = nChar;
	m_str[n] += ch;

	CSize sz = dc.GetTextExtent(m_str[n]);
	if (sz.cx > 300)
	{
		m_str[n].Delete(m_str[n].GetLength() - 1);
		n++;
		m_str[n] += ch;
	}

	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
