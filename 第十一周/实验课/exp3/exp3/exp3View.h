
// exp3View.h : Cexp3View 类的接口
//

#pragma once

class Cexp3Set;

class Cexp3View : public CRecordView
{
protected: // 仅从序列化创建
	Cexp3View();
	DECLARE_DYNCREATE(Cexp3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EXP3_FORM };
#endif
	Cexp3Set* m_pSet;

// 特性
public:
	Cexp3Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	CString nowPath;
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
	virtual ~Cexp3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordNext();
	afx_msg void OnPaint();
	afx_msg void Onbigshow();
	afx_msg void OnRecordPrev();
};

#ifndef _DEBUG  // exp3View.cpp 中的调试版本
inline Cexp3Doc* Cexp3View::GetDocument() const
   { return reinterpret_cast<Cexp3Doc*>(m_pDocument); }
#endif

