
// 3.9exp1View.h : CMy39exp1View ��Ľӿ�
//

#pragma once


class CMy39exp1View : public CView
{
protected: // �������л�����
	CMy39exp1View();
	DECLARE_DYNCREATE(CMy39exp1View)

// ����
public:
	CMy39exp1Doc* GetDocument() const;

// ����
public:
	CArray <CRect, CRect&> ca;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy39exp1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.9exp1View.cpp �еĵ��԰汾
inline CMy39exp1Doc* CMy39exp1View::GetDocument() const
   { return reinterpret_cast<CMy39exp1Doc*>(m_pDocument); }
#endif

