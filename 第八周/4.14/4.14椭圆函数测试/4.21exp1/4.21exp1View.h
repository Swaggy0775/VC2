
// 4.21exp1View.h : CMy421exp1View ��Ľӿ�
//

#pragma once


class CMy421exp1View : public CView
{
protected: // �������л�����
	CMy421exp1View();
	DECLARE_DYNCREATE(CMy421exp1View)

// ����
public:
	CMy421exp1Doc* GetDocument() const;

// ����
public:	
	CRect cr = CRect(200, 200, 500, 400);

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
	virtual ~CMy421exp1View();
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

#ifndef _DEBUG  // 4.21exp1View.cpp �еĵ��԰汾
inline CMy421exp1Doc* CMy421exp1View::GetDocument() const
   { return reinterpret_cast<CMy421exp1Doc*>(m_pDocument); }
#endif

