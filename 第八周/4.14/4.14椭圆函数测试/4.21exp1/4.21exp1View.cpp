
// 4.21exp1View.cpp : CMy421exp1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.21exp1.h"
#endif

#include "4.21exp1Doc.h"
#include "4.21exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy421exp1View

IMPLEMENT_DYNCREATE(CMy421exp1View, CView)

BEGIN_MESSAGE_MAP(CMy421exp1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy421exp1View ����/����

CMy421exp1View::CMy421exp1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy421exp1View::~CMy421exp1View()
{
}

BOOL CMy421exp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy421exp1View ����

void CMy421exp1View::OnDraw(CDC* pDC)
{
	CMy421exp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	pDC->Ellipse(cr);

}


// CMy421exp1View ��ӡ

BOOL CMy421exp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy421exp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy421exp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy421exp1View ���

#ifdef _DEBUG
void CMy421exp1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy421exp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy421exp1Doc* CMy421exp1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy421exp1Doc)));
	return (CMy421exp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy421exp1View ��Ϣ�������


void CMy421exp1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int x0 = cr.CenterPoint().x;
	int y0 = cr.CenterPoint().y;

	int a = (cr.bottom - cr.top) / 2;
	int b = (cr.right - cr.left) / 2;
	int x = point.x-x0;
	int y = point.y-y0;

	CRgn rgn;
	rgn.CreateEllipticRgn(cr.left, cr.top, cr.right, cr.bottom);
	if (rgn.PtInRegion(point))
		GetDC()->TextOutW(20, 20, _T("Yes"));
	else
		Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
