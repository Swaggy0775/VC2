
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
	ON_COMMAND(ID_Circle, &Cexp2View::OnCircle)
	ON_WM_TIMER()
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
	if (pDoc->set)
	{
		pDC->TextOutW(20,20,_T("点击菜单"));
		return;
	}
	// TODO: 在此处为本机数据添加绘制代码
	


	int temp = rand()%256;
	CPen pen(PS_SOLID,1,pDoc->m_color[rand()%5]);//根据自己需要填充颜色
	CPen *oldpen;
	oldpen = pDC->SelectObject(&pen);//选新笔
	pDC->Ellipse(CRect(pDoc->mid.x - pDoc->r, pDoc->mid.y - pDoc->r, pDoc->mid.x + pDoc->r, pDoc->mid.y + pDoc->r));
	pDC->SelectObject(oldpen);//将原来的笔选回去
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




void Cexp2View::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	CRect clientCr;
	GetClientRect(&clientCr);
	Cexp2Doc* pDoc = GetDocument();
	if (pDoc->set)
	{
		SetTimer(0, rand() % 100 + 100, NULL);//取随机500左右的数
		pDoc->set = false;
	}
	pDoc->mid = clientCr.CenterPoint();
	pDoc->r = 50;

}


void Cexp2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	Cexp2Doc* pDoc = GetDocument();
	if (pDoc->r -200 < 0 )
	{
		pDoc->r += 3;
		pDoc->color =RGB(pDoc->r-20, pDoc ->r - 20, pDoc ->r - 20);
		Invalidate();
	}
	else pDoc->r = 10;
	CView::OnTimer(nIDEvent);
}
