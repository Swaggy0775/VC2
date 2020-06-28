
// exp12View.h : Cexp12View 类的接口
//

#pragma once


class Cexp12View : public CView
{
protected: // 仅从序列化创建
	Cexp12View();
	DECLARE_DYNCREATE(Cexp12View)

// 特性
public:
	Cexp12Doc* GetDocument() const;

// 操作
public:
	CImage img;
	CString fileName;
	float img_ratio;
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
	virtual ~Cexp12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowphoto();
};

#ifndef _DEBUG  // exp12View.cpp 中的调试版本
inline Cexp12Doc* Cexp12View::GetDocument() const
   { return reinterpret_cast<Cexp12Doc*>(m_pDocument); }
#endif

