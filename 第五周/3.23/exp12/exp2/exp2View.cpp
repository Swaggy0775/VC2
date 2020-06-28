
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
	ON_COMMAND(ID_Circle, &Cexp2View::OnCircle)
	ON_WM_TIMER()
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
	if (pDoc->set)
	{
		pDC->TextOutW(20,20,_T("����˵�"));
		return;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	


	int temp = rand()%256;
	CPen pen(PS_SOLID,1,pDoc->m_color[rand()%5]);//�����Լ���Ҫ�����ɫ
	CPen *oldpen;
	oldpen = pDC->SelectObject(&pen);//ѡ�±�
	pDC->Ellipse(CRect(pDoc->mid.x - pDoc->r, pDoc->mid.y - pDoc->r, pDoc->mid.x + pDoc->r, pDoc->mid.y + pDoc->r));
	pDC->SelectObject(oldpen);//��ԭ���ı�ѡ��ȥ
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




void Cexp2View::OnCircle()
{
	// TODO: �ڴ���������������
	CRect clientCr;
	GetClientRect(&clientCr);
	Cexp2Doc* pDoc = GetDocument();
	if (pDoc->set)
	{
		SetTimer(0, rand() % 100 + 100, NULL);//ȡ���500���ҵ���
		pDoc->set = false;
	}
	pDoc->mid = clientCr.CenterPoint();
	pDoc->r = 50;

}


void Cexp2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	Cexp2Doc* pDoc = GetDocument();
	if (pDoc->r -200 < 0 )
	{
		pDoc->r += 3;
		pDoc->color =RGB(pDoc->r-20, pDoc ->r - 20, pDoc ->r - 20);
		Invalidate();
	}
	else pDoc->r = 10;
	CView::OnTimer(nIDEvent);
}
