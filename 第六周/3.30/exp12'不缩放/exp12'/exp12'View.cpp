
// exp12'View.cpp : Cexp12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp12'.h"
#endif

#include "exp12'Doc.h"
#include "exp12'View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp12View

IMPLEMENT_DYNCREATE(Cexp12View, CView)

BEGIN_MESSAGE_MAP(Cexp12View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(midShowJPG, &Cexp12View::Onmidshowjpg)
END_MESSAGE_MAP()

// Cexp12View 构造/析构

Cexp12View::Cexp12View()
{
	// TODO: 在此处添加构造代码

}

Cexp12View::~Cexp12View()
{
}

BOOL Cexp12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp12View 绘制

void Cexp12View::OnDraw(CDC* pDC)
{
	Cexp12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (img != NULL)
	{

		CRect rect;
		GetClientRect(&rect);
		int w, h, sx, sy;
		if (rect.bottom > img.GetHeight() && rect.right > img.GetWidth())//图片小于客户区
		{
			w = img.GetWidth();
			h = img.GetHeight();
			sx = rect.CenterPoint().x - w / 2;
			sy = rect.CenterPoint().y - h / 2;
			img.Draw(pDC->m_hDC, sx, sy, w, h);
		}
		else
		{
			pDC->TextOutW(20, 20, _T("客户区小于图片，无法不缩放显示"));
		}
		
	}
}


// Cexp12View 打印

BOOL Cexp12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp12View 诊断

#ifdef _DEBUG
void Cexp12View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp12Doc* Cexp12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp12Doc)));
	return (Cexp12Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp12View 消息处理程序


void Cexp12View::Onmidshowjpg()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();//使得该对话框独占窗口 返回值为给r;
	CString fileName = cfd.GetPathName();//

	if(!fileName.IsEmpty())
	{
	img.Load(fileName);//关联img对象和该图片
	CRect rect;
	GetClientRect(&rect);

	int w, h, sx, sy;

	if (rect.bottom > img.GetHeight() && rect.right > img.GetWidth())//图片小于客户区
	{
		w = img.GetWidth();
		h = img.GetHeight();
		sx = rect.CenterPoint().x - w / 2;
		sy= rect.CenterPoint().y - h / 2;
	}
	img.Draw(GetDC()->m_hDC, sx, sy, w, h);}
}
