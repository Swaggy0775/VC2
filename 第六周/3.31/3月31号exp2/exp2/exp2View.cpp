
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
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp2View 构造/析构

Cexp2View::Cexp2View()
{
	// TODO: 在此处添加构造代码
	set = false;
	font.CreatePointFont(100, TEXT("楷体"));
	Index = 0;
	for (int i = 0; i < 10; i++)
	{
		CString s;
		m_str.Add(s);
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
	CRect cr = CRect(200, 200, 1000, 400);
	pDC->Rectangle(cr);
	pDC->SelectObject(&font);

	if (m_str[0].GetLength() == 1)
	{
		pDC->SelectObject(&font);
		TEXTMETRIC tm;
		pDC->GetTextMetrics(&tm);
		width=tm.tmAveCharWidth;
		heigh = tm.tmHeight;
	}
	for (int i = 0; i <= Index;i++)
	pDC->TextOutW(sp.x +width, sp.y + heigh*(i+1), m_str[i]);

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


void Cexp2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char ch = nChar;
	if (!set)
	{
		m_str[Index] += ch;
	}
	else
	{
		m_str[Index].Insert(insertIndex, ch);
		insertIndex++;
	}

	if (m_str[Index].GetLength()*width > eP.x - sp.x - width)
	{
		m_str[Index].Delete(m_str[Index].GetLength()-1);
		Index++;
		m_str[Index] += ch;
	}
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Cexp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x < eP.x&&    point.y <sp.y + (2+Index) * heigh  &&   point.y>sp.y +(Index +1)* heigh)
	{
		set = true;
		insertIndex =int ((point.x - sp.x) / width);
	}
	CView::OnLButtonDown(nFlags, point);
}
