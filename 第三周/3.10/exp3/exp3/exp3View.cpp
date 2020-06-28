
// exp3View.cpp : Cexp3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp3View ����/����

Cexp3View::Cexp3View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp3View::~Cexp3View()
{
}

BOOL Cexp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp3View ����

void Cexp3View::OnDraw(CDC* pDC)
{
	Cexp3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	pDC->Rectangle(cr1);
	pDC->Rectangle(cr2);
	pDC->Rectangle(cr3);
	pDC->Rectangle(cr4);
}


// Cexp3View ��ӡ

BOOL Cexp3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp3View ���

#ifdef _DEBUG
void Cexp3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp3Doc* Cexp3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp3Doc)));
	return (Cexp3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp3View ��Ϣ�������


void Cexp3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Cexp3Doc* pDoc = GetDocument();
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	CClientDC dc(this);


	if (cr1.PtInRect(CPoint(point.x, point.y)))
	{
		pDoc->a = rand() % 50 + 5;
		s.Format(_T("a=%d"),pDoc->a);
		dc.TextOutW(cr1.CenterPoint().x, cr1.CenterPoint().y,s);
	}
	else if (cr2.PtInRect(CPoint(point.x, point.y)))
	{
		pDoc->b = rand() % 50 + 5;
		s.Format(_T("b=%d"), pDoc->b);
		dc.TextOutW(cr2.CenterPoint().x, cr2.CenterPoint().y, s);
	}
	else if (cr3.PtInRect(CPoint(point.x, point.y)))
	{
		if (count == 1)pDoc->s.Format(_T("%d"), pDoc->a + pDoc->b);
		
		dc.TextOutW(point.x,point.y,pDoc->s);
	}//cr3
	else if (cr4.PtInRect(CPoint(point.x, point.y)))
	{
		if (count == 1)
		{
			pDoc->s.Format(_T("%d"), pDoc->a + pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y, _T("+"));
		}
		else if (count == 2)
		{
			pDoc->s.Format(_T("%d"), pDoc->a - pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y +20, _T("-"));
		}
		else if (count == 3)
		{
			pDoc->s.Format(_T("%d"), pDoc->a * pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y+10, _T("*"));
		}
		else if (count == 4)
		{
			pDoc->s.Format(_T("%0.6f"),(float) pDoc->a / (float)pDoc->b);
			dc.TextOutW(cr4.CenterPoint().x, cr4.CenterPoint().y-10, _T("/"));
		}
		count++;
	}//cr4
	else
	{
		
		dc.TextOutW(point.x, point.y, _T("��Ч"));
	}
	CView::OnLButtonDown(nFlags, point);
}
