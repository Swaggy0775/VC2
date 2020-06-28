
// exp30View.cpp : Cexp30View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp30.h"
#endif

#include "exp30Doc.h"
#include "exp30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp30View

IMPLEMENT_DYNCREATE(Cexp30View, CView)

BEGIN_MESSAGE_MAP(Cexp30View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp30View 构造/析构

Cexp30View::Cexp30View()
{
	// TODO: 在此处添加构造代码
	

}

Cexp30View::~Cexp30View()
{
}

BOOL Cexp30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp30View 绘制

void Cexp30View::OnDraw(CDC* pDC)
{
	Cexp30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (pDoc->set)
	{
		for (int i = 0; i<pDoc->N; i++)
		{
			SetTimer(i, rand() % 400 + 100,NULL);//取随机500左右的数
			
		}//设置后 每隔x秒.
		pDoc->set = false;
	}
	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->N; i++)
	{
		pDC->Ellipse(pDoc->cr[i]); 
	}
}


// Cexp30View 打印

BOOL Cexp30View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp30View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp30View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp30View 诊断

#ifdef _DEBUG
void Cexp30View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp30Doc* Cexp30View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp30Doc)));
	return (Cexp30Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp30View 消息处理程序


void Cexp30View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp30Doc* pDoc = GetDocument();
	int i = nIDEvent;//定时器名称
	CRect cr;
	GetClientRect(&cr);

	if (pDoc->cr[i].bottom <= (cr.bottom-10) &&pDoc->set2[i])
	{
	pDoc->cr[i].bottom += 10;
	pDoc->cr[i].top += 10;
	}
	else if(pDoc->cr[i].bottom > (cr.bottom - 10) && pDoc->set2[i])
	{
		pDoc->cr[i].top += cr.bottom - pDoc->cr[i].bottom;
		pDoc->cr[i].bottom = cr.bottom;
		//KillTimer(nIDEvent);
		pDoc->set2[i] = false;
	}
	
	if (pDoc->set2[i]==false &&  (pDoc->cr[i].top-10)>=cr.top)
	{
		pDoc->cr[i].top -= 10;
		pDoc->cr[i].bottom -= 10;
	}
	else if (pDoc->set2[i] == false && (pDoc->cr[i].top - 10) < cr.top)
	{
		pDoc->cr[i].bottom -= pDoc->cr[i].top - cr.top;
		pDoc->cr[i].top = 0;
		pDoc->set2[i] = true;
		KillTimer(i);
	}

	Invalidate();
	CView::OnTimer(nIDEvent);
}
