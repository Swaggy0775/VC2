
// exp4View.cpp : Cexp4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp4.h"
#include "MyDlg.h"
#endif

#include "exp4Doc.h"
#include "exp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp4View

IMPLEMENT_DYNCREATE(Cexp4View, CView)

BEGIN_MESSAGE_MAP(Cexp4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_dlg, &Cexp4View::Ondlg)
END_MESSAGE_MAP()

// Cexp4View ����/����

Cexp4View::Cexp4View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp4View::~Cexp4View()
{
}

BOOL Cexp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp4View ����

void Cexp4View::OnDraw(CDC* /*pDC*/)
{
	Cexp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp4View ��ӡ

BOOL Cexp4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp4View ���

#ifdef _DEBUG
void Cexp4View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp4Doc* Cexp4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp4Doc)));
	return (Cexp4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp4View ��Ϣ�������


void Cexp4View::Ondlg()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	int t = dlg.DoModal();

	if (t == IDOK)
	{

	}
}
