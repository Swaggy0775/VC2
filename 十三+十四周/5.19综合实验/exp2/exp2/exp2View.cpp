
// exp2View.cpp : Cexp2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// Cexp2View 构造/析构

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
	// TODO: 在此处添加构造代码

}

Cexp2View::~Cexp2View()
{
}

void Cexp2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cexp2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp2Set;
	CRecordView::OnInitialUpdate();

}


// Cexp2View 打印

BOOL Cexp2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp2View 诊断

#ifdef _DEBUG
void Cexp2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp2Doc* Cexp2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2Doc)));
	return (Cexp2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2View 数据库支持
CRecordset* Cexp2View::OnGetRecordset()
{
	return m_pSet;
}




void Cexp2View::OnQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	SqlDlg dlg;
	int r = dlg.DoModal();

	if (r == IDOK)
	{
		m_pSet->m_strFilter = dlg.Command;
		m_pSet->Requery();
		if (m_pSet->GetRecordCount() == 0)
		{
			MessageBox(_T("无符合的记录"));
			//OnRestore();
		}


		InvalidateRect(&rect, true);
		RedrawWindow();

		UpdateData(false);
	}
}


void Cexp2View::OnSort()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();

	InvalidateRect(&rect, true);
	RedrawWindow();

	UpdateData(false);
}


void Cexp2View::OnTraver()
{
	// TODO: 在此添加控件通知处理程序代码
	TaverDlg dlg;
	dlg.m_DlgpSet = m_pSet;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void Cexp2View::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
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
			MessageBox(_T("未填入主键"));
	}
}


void Cexp2View::OnDelete()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->Delete();

	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MovePrev();
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnModifi()
{
	// TODO: 在此添加命令处理程序代码
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

		m_pSet->Update();//只有在addnew（）或edit（）后调用update才有意义。

		InvalidateRect(&rect, true);
		RedrawWindow();
		UpdateData(false);
	}
}




bool set = false;
void Cexp2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()

	if (!set)
	{
		MessageBox(_T("打开菜单中的视图  可以增删改, 修改时也可以只改一个键"));
		set = true;
	}
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_picture为picture控件ID
	pWnd->GetClientRect(&rect);//rc为控件的大小

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

		pDC->TextOutW(20, 20, _T("图片不存在"));
	}
	img.Destroy();
	ReleaseDC(pDC);//释放DC 注意获取后必须释放
}


void Cexp2View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();

	//nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();

	//nowPath = m_pSet->column2;
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
}


void Cexp2View::OnShowPic()
{
	// TODO: 在此添加控件通知处理程序代码
	PicDlg dlg;
	dlg.path = m_pSet->column3;
	int r =dlg.DoModal();
	if(r==IDOK)
	{

	}
}


