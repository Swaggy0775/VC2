
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
	int set=0;
	CPoint s;
	CPoint e;
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
	afx_msg void OnMakeline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMakerect();
	afx_msg void OnMakeeillpse();
};

#ifndef _DEBUG  // exp2View.cpp �еĵ��԰汾
inline Cexp2Doc* Cexp2View::GetDocument() const
   { return reinterpret_cast<Cexp2Doc*>(m_pDocument); }
#endif

