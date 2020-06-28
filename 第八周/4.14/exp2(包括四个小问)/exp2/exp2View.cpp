
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
#include "MyDlg1.h"
#include "MyDlg2.h"
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(EilipseColor, &Cexp2View::OnEilipsecolor)
	ON_COMMAND(ICreateEilipse, &Cexp2View::OnICreateeilipse)
END_MESSAGE_MAP()

// Cexp2View ����/����

Cexp2View::Cexp2View()
{
	// TODO: �ڴ˴���ӹ������
	for (int i = 0; i < 50; i++)
	{
		CRect cr;
		crs.Add(cr);
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

	if (vline)
	{
		CPen newpen;//�����Լ���Ҫ�����ɫ
		CPen *oldpen;
		newpen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
		oldpen = pDC->SelectObject(&newpen);//ѡ�¶ȵĻ�ˢ
		pDC->Rectangle(crs[vline - 1]);
		pDC->SelectObject(oldpen);
	}
	for (int i = 0; i <= index; i++)
	{
		pDC->Ellipse(crs[i]);
	}
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


void Cexp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	vline = 0;
	set = true;
	s = point;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	if (sqrt(abs((point.x - s.x)*(point.x - s.x) + (point.y - s.y)*(point.y - s.y))) < 1.0 && index>0)
	{
		for (int i = 0; i <= index; i++)
		{
			CRgn rgn;
			rgn.CreateEllipticRgn(crs[i].left, crs[i].top, crs[i].right, crs[i].bottom);
			if (rgn.PtInRegion(point))
			{ 
				vline = i+1;
				Invalidate();
				}
		}
		return;
	}
	index++;
		
	CView::OnLButtonUp(nFlags, point);
}


void Cexp2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set)
	{
		crs[index].SetRect(min(point.x,s.x), min(point.y, s.y), max(point.x, s.x), max(point.y, s.y) );
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


//void Cexp2View::OnIshoweilipse()
//{
//	// TODO: �ڴ���������������
//}



void Cexp2View::OnEilipsecolor()
{
	// TODO: �ڴ���������������
	MyDlg2 dlg;
	int r=dlg.DoModal();
	CDC* pDC = GetDC();
	CBrush brush(dlg.color);//�����Լ���Ҫ�����ɫ
	CBrush *oldbrush;

	if (r == IDOK)
	{
	oldbrush = pDC->SelectObject(&brush);//ѡ�¶ȵĻ�ˢ

	for (int i = 0; i <= index; i++)pDC->Ellipse(crs[i]);

	pDC->SelectObject(oldbrush);//��ԭ���Ļ�ˢѡ��ȥ
	}
}





void Cexp2View::OnICreateeilipse()
{
	// TODO: �ڴ���������������
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		for (int i = 0; i < dlg.n; i++)
		{
			crs[index] = dlg.crs[i];
			index++;
		}
		Invalidate();
	}
}
