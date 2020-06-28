
// exp30View.cpp : Cexp30View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp30View ����/����

Cexp30View::Cexp30View()
{
	// TODO: �ڴ˴���ӹ������
	

}

Cexp30View::~Cexp30View()
{
}

BOOL Cexp30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp30View ����

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
			SetTimer(i, rand() % 400 + 100,NULL);//ȡ���500���ҵ���
			
		}//���ú� ÿ��x��.
		pDoc->set = false;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->N; i++)
	{
		pDC->Ellipse(pDoc->cr[i]); 
	}
}


// Cexp30View ��ӡ

BOOL Cexp30View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp30View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp30View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp30View ���

#ifdef _DEBUG
void Cexp30View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp30Doc* Cexp30View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp30Doc)));
	return (Cexp30Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp30View ��Ϣ�������


void Cexp30View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp30Doc* pDoc = GetDocument();
	int i = nIDEvent;//��ʱ������
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
