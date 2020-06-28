
// 3.9exp1View.h : CMy39exp1View 类的接口
//

#pragma once


class CMy39exp1View : public CView
{
protected: // 仅从序列化创建
	CMy39exp1View();
	DECLARE_DYNCREATE(CMy39exp1View)

// 特性
public:
	CMy39exp1Doc* GetDocument() const;

// 操作
public:
	CArray <CRect, CRect&> ca;
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
	virtual ~CMy39exp1View();
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
};

#ifndef _DEBUG  // 3.9exp1View.cpp 中的调试版本
inline CMy39exp1Doc* CMy39exp1View::GetDocument() const
   { return reinterpret_cast<CMy39exp1Doc*>(m_pDocument); }
#endif

