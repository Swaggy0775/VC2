
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
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp3View ����/����

Cexp3View::Cexp3View()
{
	// TODO: �ڴ˴���ӹ������
	for (int i = 0; i < 10; i++)
	{
		CString s;
		m_str.Add(s);
	}
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
	CRect cr = CRect(200, 200, 500, 400);
	pDC->Rectangle(cr);
	for (int i = 0; i < n+1; i++)
	{
		pDC->TextOutW(s.x+1, s.y+1 + 20 * i, m_str[i]);
	}
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


void Cexp3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	char ch = nChar;
	m_str[n] += ch;

	CSize sz = dc.GetTextExtent(m_str[n]);
	if (sz.cx > 300)
	{
		m_str[n].Delete(m_str[n].GetLength() - 1);
		n++;
		m_str[n] += ch;
	}

	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
