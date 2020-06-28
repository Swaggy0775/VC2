
// exp12View.cpp : Cexp12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp12.h"
#endif

#include "exp12Doc.h"
#include "exp12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp12View

IMPLEMENT_DYNCREATE(Cexp12View, CView)

BEGIN_MESSAGE_MAP(Cexp12View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowPhoto, &Cexp12View::OnShowphoto)
END_MESSAGE_MAP()

// Cexp12View ����/����

Cexp12View::Cexp12View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp12View::~Cexp12View()
{
}

BOOL Cexp12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp12View ����

void Cexp12View::OnDraw(CDC* pDC)
{
	Cexp12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (img!=NULL)
	{
		

		CRect rect;
		GetClientRect(&rect);
		if (rect.top >=rect.bottom)
			return;//����߽�

		int w, h, sx, sy;
		float r_ratio = 1.0*rect.Width() / rect.Height();

		if (r_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}



		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}
}


// Cexp12View ��ӡ

BOOL Cexp12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp12View ���

#ifdef _DEBUG
void Cexp12View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp12Doc* Cexp12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp12Doc)));
	return (Cexp12Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp12View ��Ϣ�������


void Cexp12View::OnShowphoto()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();//ʹ�øöԻ����ռ���� ����ֵΪ��r;
	CString fileName = cfd.GetPathName();//

	img.Load(fileName);//����img����͸�ͼƬ


	CRect rect;
	GetClientRect(&rect);

	int w, h, sx, sy;
	float r_ratio = 1.0*rect.Width() / rect.Height();
	img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (r_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	img.Draw(GetDC()->m_hDC, sx, sy, w, h);
}
