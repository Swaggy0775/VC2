
// exp_dbView.cpp : Cexp_dbView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp_db.h"
#endif

#include "exp_dbSet.h"
#include "exp_dbDoc.h"
#include "exp_dbView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp_dbView

IMPLEMENT_DYNCREATE(Cexp_dbView, CRecordView)

BEGIN_MESSAGE_MAP(Cexp_dbView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_EDIT1, &Cexp_dbView::OnEnChangeEdit1)
END_MESSAGE_MAP()

// Cexp_dbView ����/����

Cexp_dbView::Cexp_dbView()
	: CRecordView(IDD_EXP_DB_FORM)
	, ID(0)
	, name(_T(""))
	, sno(_T(""))
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

Cexp_dbView::~Cexp_dbView()
{
}

void Cexp_dbView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_F1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL Cexp_dbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cexp_dbView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp_dbSet;
	CRecordView::OnInitialUpdate();

}


// Cexp_dbView ��ӡ

BOOL Cexp_dbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp_dbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp_dbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp_dbView ���

#ifdef _DEBUG
void Cexp_dbView::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp_dbView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp_dbDoc* Cexp_dbView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp_dbDoc)));
	return (Cexp_dbDoc*)m_pDocument;
}
#endif //_DEBUG


// Cexp_dbView ���ݿ�֧��
CRecordset* Cexp_dbView::OnGetRecordset()
{
	return m_pSet;
}



// Cexp_dbView ��Ϣ�������


void Cexp_dbView::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
