
// exp2View.h : Cexp2View 类的接口
//

#pragma once


class Cexp2View : public CView
{
protected: // 仅从序列化创建
	Cexp2View();
	DECLARE_DYNCREATE(Cexp2View)

// 特性
public:
	Cexp2Doc* GetDocument() const;

// 操作
public:
	CArray <CRect, CRect&> crs;
	int index = 0;
	bool set=false;
	CPoint s;
	int vline=0;
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
	virtual ~Cexp2View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnEilipsecolor();
	afx_msg void OnICreateeilipse();
};

#ifndef _DEBUG  // exp2View.cpp 中的调试版本
inline Cexp2Doc* Cexp2View::GetDocument() const
   { return reinterpret_cast<Cexp2Doc*>(m_pDocument); }
#endif

