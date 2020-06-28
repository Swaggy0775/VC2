
// exp1View.cpp : Cexp1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp1.h"
#endif

#include "exp1Set.h"
#include "exp1Doc.h"
#include "exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1View

IMPLEMENT_DYNCREATE(Cexp1View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp1View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp1View::OnBnClickedPic)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_NEXT, &Cexp1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &Cexp1View::OnRecordPrev)
END_MESSAGE_MAP()

// Cexp1View ����/����

Cexp1View::Cexp1View()
	: CRecordView(IDD_EXP1_FORM)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������


}

Cexp1View::~Cexp1View()
{
}

void Cexp1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
}

BOOL Cexp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cexp1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp1Set;
	CRecordView::OnInitialUpdate();


	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_pictureΪpicture�ؼ�ID
	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С
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
	CRecordView::AssertValid();
}

void Cexp1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp1Doc* Cexp1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1Doc)));
	return (Cexp1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1View ���ݿ�֧��
CRecordset* Cexp1View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp1View ��Ϣ�������

void Cexp1View::drawimg(CString ss)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CImage img;
	img.Load(ss);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	if (!img.IsNull())
	{
		

		int w, h, sx, sy;
		float r_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
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

	else
	{
		pDC->TextOutW(20,20,_T("ͼƬ������"));
	}
}


void Cexp1View::OnBnClickedPic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	drawimg(m_pSet->column2	);//������filePath��?
}


void Cexp1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
}




void Cexp1View::OnRecordNext()
{
	// TODO: �ڴ���������������
	
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();

	InvalidateRect(&rect,true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp1View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();

	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}
