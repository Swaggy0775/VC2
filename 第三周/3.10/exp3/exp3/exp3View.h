
// exp3View.h : Cexp3View 类的接口
//

#pragma once
#include "atltypes.h"


class Cexp3View : public CView
{
protected: // 仅从序列化创建
	Cexp3View();
	DECLARE_DYNCREATE(Cexp3View)

// 特性
public:
	Cexp3Doc* GetDocument() const;

// 操作
public:
	CRect cr1 = CRect(100, 20, 200, 100);
	CRect cr2 = CRect(200, 20, 300, 100);
	CRect cr3 = CRect(300, 20, 400, 100);
	CRect cr4 = CRect(200, 120, 300, 200);
	int count=1;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// 记录点击次数// 记录点击次数
};

#ifndef _DEBUG  // exp3View.cpp 中的调试版本
inline Cexp3Doc* Cexp3View::GetDocument() const
   { return reinterpret_cast<Cexp3Doc*>(m_pDocument); }
#endif

