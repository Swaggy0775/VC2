
// exp2View.h : Cexp2View ��Ľӿ�
//

#pragma once


class Cexp2View : public CView
{
protected: // �������л�����
	Cexp2View();
	DECLARE_DYNCREATE(Cexp2View)

// ����
public:
	Cexp2Doc* GetDocument() const;

// ����
public:
	bool set = false;
	CRect cr;
	CPoint sp;
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
	virtual ~Cexp2View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp2View.cpp �еĵ��԰汾
inline Cexp2Doc* Cexp2View::GetDocument() const
   { return reinterpret_cast<Cexp2Doc*>(m_pDocument); }
#endif

