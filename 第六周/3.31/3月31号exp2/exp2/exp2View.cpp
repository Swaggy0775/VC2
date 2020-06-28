
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
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp2View ����/����

Cexp2View::Cexp2View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	font.CreatePointFont(100, TEXT("����"));
	Index = 0;
	for (int i = 0; i < 10; i++)
	{
		CString s;
		m_str.Add(s);
	}
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
	CRect cr = CRect(200, 200, 1000, 400);
	pDC->Rectangle(cr);
	pDC->SelectObject(&font);

	if (m_str[0].GetLength() == 1)
	{
		pDC->SelectObject(&font);
		TEXTMETRIC tm;
		pDC->GetTextMetrics(&tm);
		width=tm.tmAveCharWidth;
		heigh = tm.tmHeight;
	}
	for (int i = 0; i <= Index;i++)
	pDC->TextOutW(sp.x +width, sp.y + heigh*(i+1), m_str[i]);

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


void Cexp2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	char ch = nChar;
	if (!set)
	{
		m_str[Index] += ch;
	}
	else
	{
		m_str[Index].Insert(insertIndex, ch);
		insertIndex++;
	}

	if (m_str[Index].GetLength()*width > eP.x - sp.x - width)
	{
		m_str[Index].Delete(m_str[Index].GetLength()-1);
		Index++;
		m_str[Index] += ch;
	}
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Cexp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x < eP.x&&    point.y <sp.y + (2+Index) * heigh  &&   point.y>sp.y +(Index +1)* heigh)
	{
		set = true;
		insertIndex =int ((point.x - sp.x) / width);
	}
	CView::OnLButtonDown(nFlags, point);
}
