
// 3.9exp1View.cpp : CMy39exp1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.9exp1.h"
#endif

#include "3.9exp1Doc.h"
#include "3.9exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy39exp1View

IMPLEMENT_DYNCREATE(CMy39exp1View, CView)

BEGIN_MESSAGE_MAP(CMy39exp1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy39exp1View ����/����

CMy39exp1View::CMy39exp1View()
{
	// TODO: �ڴ˴���ӹ������
	CRect cr = CRect(0, 0, 0, 0);
	ca.Add(cr);
}

CMy39exp1View::~CMy39exp1View()
{
}

BOOL CMy39exp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy39exp1View ����

void CMy39exp1View::OnDraw(CDC* pDC)
{
	CMy39exp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(ca.GetAt(0));
}


// CMy39exp1View ��ӡ

BOOL CMy39exp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy39exp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy39exp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy39exp1View ���

#ifdef _DEBUG
void CMy39exp1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy39exp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy39exp1Doc* CMy39exp1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy39exp1Doc)));
	return (CMy39exp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy39exp1View ��Ϣ�������


void CMy39exp1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dr(this);
	int min;
	if (cr.Width()< cr.Height())
	{
		min = cr.Width();
	}
	else {
		min = cr.Height();
	}
	CRect cr1 = CRect(0, 0, min, min);
	dr.Ellipse(cr1);
	ca[0] = cr1;
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
