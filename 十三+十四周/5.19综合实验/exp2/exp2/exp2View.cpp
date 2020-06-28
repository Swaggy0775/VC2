
// exp2View.cpp : Cexp2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp2.h"
#endif
#include "TaverDlg.h"
#include "SqlDlg.h"
#include "AddDlg.h"
#include "exp2Set.h"
#include "exp2Doc.h"
#include "exp2View.h"
#include "PicDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp2View

IMPLEMENT_DYNCREATE(Cexp2View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp2View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp2View::OnQuery)
	ON_BN_CLICKED(IDC_BUTTON2, &Cexp2View::OnSort)
	ON_BN_CLICKED(IDC_BUTTON3, &Cexp2View::OnRestore)
	ON_BN_CLICKED(IDC_BUTTON4, &Cexp2View::OnTraver)
	ON_COMMAND(ID_Add, &Cexp2View::OnAdd)
	ON_COMMAND(ID_Delete, &Cexp2View::OnDelete)
	ON_COMMAND(ID_Modifi, &Cexp2View::OnModifi)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &Cexp2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &Cexp2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &Cexp2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &Cexp2View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON5, &Cexp2View::OnShowPic)
END_MESSAGE_MAP()

// Cexp2View ����/����

Cexp2View::Cexp2View()
	: CRecordView(IDD_EXP2_FORM)
	, Name(_T(""))
	, Sno(_T(""))
	, Age(0)
	, Salary(0)
	, prof(_T(""))
	, Sex(_T(""))
	, Birthday(_T(""))
	, telephone(_T(""))
	, Address(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

Cexp2View::~Cexp2View()
{
}

void Cexp2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column8);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column9);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->column10);
}

BOOL Cexp2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cexp2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp2Set;
	CRecordView::OnInitialUpdate();

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
	CRecordView::AssertValid();
}

void Cexp2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp2Doc* Cexp2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2Doc)));
	return (Cexp2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2View ���ݿ�֧��
CRecordset* Cexp2View::OnGetRecordset()
{
	return m_pSet;
}




void Cexp2View::OnQuery()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SqlDlg dlg;
	int r = dlg.DoModal();

	if (r == IDOK)
	{
		m_pSet->m_strFilter = dlg.Command;
		m_pSet->Requery();
		if (m_pSet->GetRecordCount() == 0)
		{
			MessageBox(_T("�޷��ϵļ�¼"));
			//OnRestore();
		}


		InvalidateRect(&rect, true);
		RedrawWindow();

		UpdateData(false);
	}
}


void Cexp2View::OnSort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SqlDlg dlg;
	int r = dlg.DoModal();

	if (r == IDOK)
	{
		m_pSet->m_strSort = dlg.Command;
		m_pSet->Requery();

		InvalidateRect(&rect, true);
		RedrawWindow();

		UpdateData(false);
	}
}


void Cexp2View::OnRestore()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();

	InvalidateRect(&rect, true);
	RedrawWindow();

	UpdateData(false);
}


void Cexp2View::OnTraver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TaverDlg dlg;
	dlg.m_DlgpSet = m_pSet;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void Cexp2View::OnAdd()
{
	// TODO: �ڴ���������������
	AddDlg dlg;
	int r =dlg.DoModal();
	if (r == IDOK)
	{
		if (!dlg.Sno.IsEmpty())
		{
			m_pSet->AddNew();
			m_pSet->column1 = dlg.Name;
			m_pSet->column2 = dlg.Sno;
			m_pSet->column3 = dlg.PicPath;
			m_pSet->column4 = dlg.Age;
			m_pSet->column5 = dlg.Salary;
			m_pSet->column6 = dlg.prof;
			m_pSet->column7 = dlg.prof;
			m_pSet->column8 = dlg.Birthday;
			m_pSet->column9 = dlg.Telephone;
			m_pSet->column10 = dlg.Addre;
			m_pSet->Update();
			UpdateData(false);
		}
		else
			MessageBox(_T("δ��������"));
	}
}


void Cexp2View::OnDelete()
{
	// TODO: �ڴ���������������
	m_pSet->Delete();

	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MovePrev();
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnModifi()
{
	// TODO: �ڴ���������������
	AddDlg dlg;
	dlg.Name = m_pSet->column1;
	dlg.Sno= m_pSet->column2;
	dlg.PicPath = m_pSet->column3;
	dlg.Age = m_pSet->column4;
	dlg.Salary = m_pSet->column5;
	dlg.prof = m_pSet->column6;
	dlg.Sex = m_pSet->column7;
	dlg.Birthday = m_pSet->column8;
	dlg.Telephone = m_pSet->column9;
	dlg.Addre = m_pSet->column10;
	int r = dlg.DoModal();

	if (r == IDOK)
	{
		m_pSet->Edit();

		if(!dlg.Name.IsEmpty())
		m_pSet->column1 = dlg.Name;

		if (!dlg.Sno.IsEmpty())
		m_pSet->column2 = dlg.Sno;


		if (!dlg.PicPath.IsEmpty())
		{
			m_pSet->column3 = dlg.PicPath;
		}
		if (dlg.Age>0)
		m_pSet->column4 = dlg.Age;

		
		if (dlg.Salary >0)
			m_pSet->column5 = dlg.Salary;

		if (!dlg.prof.IsEmpty())
			m_pSet->column6 = dlg.prof;		
		
		if (!dlg.Sex.IsEmpty())
			m_pSet->column7 = dlg.Sex;

		if (!dlg.Birthday.IsEmpty())
			m_pSet->column8 = dlg.Birthday;

		if (!dlg.Telephone.IsEmpty())
			m_pSet->column9 = dlg.Telephone;

		if (!dlg.Addre.IsEmpty())
			m_pSet->column10 = dlg.Addre;

		m_pSet->Update();//ֻ����addnew������edit���������update�������塣

		InvalidateRect(&rect, true);
		RedrawWindow();
		UpdateData(false);
	}
}




bool set = false;
void Cexp2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()

	if (!set)
	{
		MessageBox(_T("�򿪲˵��е���ͼ  ������ɾ��, �޸�ʱҲ����ֻ��һ����"));
		set = true;
	}
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_pictureΪpicture�ؼ�ID
	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С

	CImage img;
	img.Load(m_pSet->column3);
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
	}//Null

	else
	{

		pDC->TextOutW(20, 20, _T("ͼƬ������"));
	}
	img.Destroy();
	ReleaseDC(pDC);//�ͷ�DC ע���ȡ������ͷ�
}


void Cexp2View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();

	//nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();

	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();

	//nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();

	//nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();

	//nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnShowPic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PicDlg dlg;
	dlg.path = m_pSet->column3;
	int r =dlg.DoModal();
	if(r==IDOK)
	{

	}
}


