
// exp_dbView.cpp : Cexp_dbView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_EDIT1, &Cexp_dbView::OnEnChangeEdit1)
END_MESSAGE_MAP()

// Cexp_dbView 构造/析构

Cexp_dbView::Cexp_dbView()
	: CRecordView(IDD_EXP_DB_FORM)
	, ID(0)
	, name(_T(""))
	, sno(_T(""))
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

Cexp_dbView::~Cexp_dbView()
{
}

void Cexp_dbView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_F1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL Cexp_dbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cexp_dbView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp_dbSet;
	CRecordView::OnInitialUpdate();

}


// Cexp_dbView 打印

BOOL Cexp_dbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp_dbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp_dbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp_dbView 诊断

#ifdef _DEBUG
void Cexp_dbView::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp_dbView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp_dbDoc* Cexp_dbView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp_dbDoc)));
	return (Cexp_dbDoc*)m_pDocument;
}
#endif //_DEBUG


// Cexp_dbView 数据库支持
CRecordset* Cexp_dbView::OnGetRecordset()
{
	return m_pSet;
}



// Cexp_dbView 消息处理程序


void Cexp_dbView::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
