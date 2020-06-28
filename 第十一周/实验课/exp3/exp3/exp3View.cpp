
// exp3View.cpp : Cexp3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_NEXT, &Cexp3View::OnRecordNext)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp3View::Onbigshow)
	ON_COMMAND(ID_RECORD_PREV, &Cexp3View::OnRecordPrev)
END_MESSAGE_MAP()

// Cexp3View 构造/析构

Cexp3View::Cexp3View()
	: CRecordView(IDD_EXP3_FORM)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

Cexp3View::~Cexp3View()
{
}

void Cexp3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);

}

BOOL Cexp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cexp3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp3Set;
	CRecordView::OnInitialUpdate();


	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_picture为picture控件ID
	pWnd->GetClientRect(&rect);//rc为控件的大小
	nowPath = m_pSet->column2;
}//变量初始化


// Cexp3View 打印

BOOL Cexp3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp3View 诊断

#ifdef _DEBUG
void Cexp3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp3Doc* Cexp3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp3Doc)));
	return (Cexp3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp3View 数据库支持
CRecordset* Cexp3View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp3View 消息处理程序


void Cexp3View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	
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
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()

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
		pDC->TextOutW(20, 20, _T("图片不存在"));
	}
}


void Cexp3View::Onbigshow()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	dlg.photoPath = m_pSet->column2;
	int r =dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void Cexp3View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();

	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();

	nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}
