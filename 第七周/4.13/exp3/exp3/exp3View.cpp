
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
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
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
		CRect clientCr;
		GetClientRect(&clientCr);
	if (!set)
	{
		cr = CRect(0, clientCr.bottom / 2 - r, 2 * r, clientCr.bottom / 2 + r);
	}

	if (cr.bottom<clientCr.bottom/2)
	{
		cr.top = clientCr.bottom/2 - r;
		cr.bottom = clientCr.bottom / 2 + r;
	}

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	pDC->Ellipse(cr);
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


//void Cexp3View::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CView::OnLButtonUp(nFlags, point);
//}


void Cexp3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent;
	CRect clientCr;
	GetClientRect(&clientCr);


	if (set2 == false)
	{
		cr.right += 20;
		cr.left += 20;

		if (cr.right > clientCr.right) set2 = true;
	}//����



	if (set2 == true)
	{
		cr.left -= 20;
		cr.right -= 20;
		if (cr.left < clientCr.left)set2 = false;
	}//����
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void Cexp3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetTimer(0, 50, NULL);
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	KillTimer(0);
	CView::OnLButtonDblClk(nFlags, point);
}
