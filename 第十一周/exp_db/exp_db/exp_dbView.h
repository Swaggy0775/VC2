
// exp_dbView.h : Cexp_dbView 类的接口
//

#pragma once

class Cexp_dbSet;

class Cexp_dbView : public CRecordView
{
protected: // 仅从序列化创建
	Cexp_dbView();
	DECLARE_DYNCREATE(Cexp_dbView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EXP_DB_FORM };
#endif
	Cexp_dbSet* m_pSet;

// 特性
public:
	Cexp_dbDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cexp_dbView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	double ID;
	CString name;
	CString sno;
	double age;
	double phone;
};

#ifndef _DEBUG  // exp_dbView.cpp 中的调试版本
inline Cexp_dbDoc* Cexp_dbView::GetDocument() const
   { return reinterpret_cast<Cexp_dbDoc*>(m_pDocument); }
#endif

