
// exp3View.cpp : Cexp3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp3.h"
#endif

#include "exp3Set.h"
#include "exp3Doc.h"
#include "exp3View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp3View

IMPLEMENT_DYNCREATE(Cexp3View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp3View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_NEXT, &Cexp3View::OnRecordNext)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp3View::Onbigshow)
	ON_COMMAND(ID_RECORD_PREV, &Cexp3View::OnRecordPrev)
END_MESSAGE_MAP()

// Cexp3View ����/����

Cexp3View::Cexp3View()
	: CRecordView(IDD_EXP3_FORM)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

Cexp3View::~Cexp3View()
{
}

void Cexp3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);

}

BOOL Cexp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cexp3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp3Set;
	CRecordView::OnInitialUpdate();


	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_pictureΪpicture�ؼ�ID
	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С
	nowPath = m_pSet->column2;
}//������ʼ��


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
	CRecordView::AssertValid();
}

void Cexp3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp3Doc* Cexp3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp3Doc)));
	return (Cexp3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp3View ���ݿ�֧��
CRecordset* Cexp3View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp3View ��Ϣ�������


void Cexp3View::OnRecordNext()
{
	// TODO: �ڴ���������������
	
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();

	nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()

	CImage img;
	img.Load(nowPath);
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
		pDC->TextOutW(20, 20, _T("ͼƬ������"));
	}
}


void Cexp3View::Onbigshow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg dlg;
	dlg.photoPath = m_pSet->column2;
	int r =dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void Cexp3View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();

	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();

	nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}
