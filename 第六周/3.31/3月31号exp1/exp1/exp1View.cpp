
// exp1View.cpp : Cexp1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp1.h"
#endif

#include "exp1Doc.h"
#include "exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1View

IMPLEMENT_DYNCREATE(Cexp1View, CView)

BEGIN_MESSAGE_MAP(Cexp1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp1View ����/����

Cexp1View::Cexp1View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp1View::~Cexp1View()
{
}

BOOL Cexp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1View ����

void Cexp1View::OnDraw(CDC* pDC)
{
	Cexp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CSize sz = pDC->GetTextExtent(str);


	//CString n;n.Format(_T("%d"),sz.cx);

	CRect cr=CRect(200,200,500,400);
	pDC->Rectangle(cr);
	if (sz.cx > 300)
	{
		pDC->TextOutW(100, 100, _T("�޷���������"));
		str.Delete(str.GetLength() - 1);
		pDC->TextOutW(s.x + 1, s.y + 1, str);
		set = true;
		return;
	}
	pDC->TextOutW(s.x+1, s.y+1, str);
}


// Cexp1View ��ӡ

BOOL Cexp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp1View ���

#ifdef _DEBUG
void Cexp1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1Doc* Cexp1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1Doc)));
	return (Cexp1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1View ��Ϣ�������


void Cexp1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set == true)return;

	CClientDC dc(this);
	char ch = nChar;
	str += ch;
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Cexp1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnLButtonDown(nFlags, point);
}
