
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
	CRect rect;
	GetClientRect(&rect);//获取客户窗口
	CBrush brush(RGB(0, 0, 0));//根据自己需要填充颜色
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//选新的画刷
	pDC->Ellipse(0, 0, rect.right, rect.bottom);//建立椭圆并在其中上色RGB（x,x,x）
	pDC->SelectObject(oldbrush);//将原来的画刷选回去

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
