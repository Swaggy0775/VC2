
// exp3View.h : Cexp3View ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class Cexp3View : public CView
{
protected: // �������л�����
	Cexp3View();
	DECLARE_DYNCREATE(Cexp3View)

// ����
public:
	Cexp3Doc* GetDocument() const;

// ����
public:
	CRect cr1 = CRect(100, 20, 200, 100);
	CRect cr2 = CRect(200, 20, 300, 100);
	CRect cr3 = CRect(300, 20, 400, 100);
	CRect cr4 = CRect(200, 120, 300, 200);
	int count=1;
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
	virtual ~Cexp3View();
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
	// ��¼�������// ��¼�������
};

#ifndef _DEBUG  // exp3View.cpp �еĵ��԰汾
inline Cexp3Doc* Cexp3View::GetDocument() const
   { return reinterpret_cast<Cexp3Doc*>(m_pDocument); }
#endif

