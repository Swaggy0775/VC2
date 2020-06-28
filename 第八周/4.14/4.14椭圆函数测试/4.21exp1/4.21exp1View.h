
// 4.21exp1View.h : CMy421exp1View 类的接口
//

#pragma once


class CMy421exp1View : public CView
{
protected: // 仅从序列化创建
	CMy421exp1View();
	DECLARE_DYNCREATE(CMy421exp1View)

// 特性
public:
	CMy421exp1Doc* GetDocument() const;

// 操作
public:	
	CRect cr = CRect(200, 200, 500, 400);

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
	virtual ~CMy421exp1View();
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

#ifndef _DEBUG  // 4.21exp1View.cpp 中的调试版本
inline CMy421exp1Doc* CMy421exp1View::GetDocument() const
   { return reinterpret_cast<CMy421exp1Doc*>(m_pDocument); }
#endif

