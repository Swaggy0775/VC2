
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
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
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
	pDC->Rectangle(pDoc->cr);
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


void Cexp2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp2Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);//��Ҫ�ͻ���������Ϣ ��Ϊͼ���ƶ�Ҫ�ڿͻ�����
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->cr.left - 50> clientRec.left)
		{
			pDoc->cr.left -= 50;
			pDoc->cr.right -= 50;
		}
		else
		{
			pDoc->cr.right -= pDoc->cr.left;
			pDoc->cr.left = 0;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right + 50 < clientRec.right)
		{
			pDoc->cr.left += 50;
			pDoc->cr.right += 50;
		}
		else
		{
			pDoc->cr.left += clientRec.right - pDoc->cr.right;
			pDoc->cr.right = clientRec.right;
		}
		break;
	case VK_UP:
		if (pDoc->cr.top-50>clientRec.top)
		{
			pDoc->cr.bottom -= 50;
			pDoc->cr.top -= 50;
		}
		else
		{
			pDoc->cr.bottom -= pDoc->cr.top - clientRec.top;
			pDoc->cr.top = 0;
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom + 50<clientRec.bottom)
		{
			pDoc->cr.bottom += 50;
			pDoc->cr.top += 50;
		}
		else
		{
			pDoc->cr.top -= pDoc->cr.bottom - clientRec.bottom;
			pDoc->cr.bottom = clientRec.bottom;
		}
		break;
	case VK_HOME:
		if((pDoc->cr.bottom!= pDoc->cr.top) &&(pDoc->cr.left!=pDoc->cr.right))
		{
			pDoc->cr.left -=50;
			pDoc->cr.top -=50;
		}
		break;

	case VK_END:
		if ((pDoc->cr.bottom != pDoc->cr.top) && (pDoc->cr.left != pDoc->cr.right))
		{
			pDoc->cr.left += 50;
			pDoc->cr.top += 50;
		}
		break;
	}

	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Cexp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp2Doc* pDoc = GetDocument();
	pDoc->cr = pDoc->cr2;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
