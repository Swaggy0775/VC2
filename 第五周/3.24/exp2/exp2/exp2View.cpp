
// exp2View.cpp : Cexp2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_MakeLine, &Cexp2View::OnMakeline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MakeRect, &Cexp2View::OnMakerect)
	ON_COMMAND(ID_MakeEillpse, &Cexp2View::OnMakeeillpse)
END_MESSAGE_MAP()

// Cexp2View ����/����

Cexp2View::Cexp2View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp2View::~Cexp2View()
{
}

BOOL Cexp2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp2View ����

void Cexp2View::OnDraw(CDC* pDC)
{
	Cexp2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set == 1)
	{
		pDC->MoveTo(s.x, s.y);
		pDC->LineTo(e.x, e.y);
	}
	if (set == 2)
		pDC->Rectangle(CRect(s.x, s.y, e.x, e.y));
	if(set==3)
	pDC->Ellipse(CRect(s.x, s.y, e.x, e.y));
	
}


// Cexp2View ��ӡ

BOOL Cexp2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp2View ���

#ifdef _DEBUG
void Cexp2View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp2Doc* Cexp2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2Doc)));
	return (Cexp2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2View ��Ϣ�������


void Cexp2View::OnMakeline()
{
	// TODO: �ڴ���������������
	set = 1;
}


void Cexp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	s = point;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	e = point;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp2View::OnMakerect()
{
	// TODO: �ڴ���������������
	set = 2;
}


void Cexp2View::OnMakeeillpse()
{
	// TODO: �ڴ���������������
	set = 3;
}
