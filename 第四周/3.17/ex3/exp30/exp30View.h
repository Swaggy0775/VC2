
// exp30View.h : Cexp30View ��Ľӿ�
//

#pragma once


class Cexp30View : public CView
{
protected: // �������л�����
	Cexp30View();
	DECLARE_DYNCREATE(Cexp30View)

// ����
public:
	Cexp30Doc* GetDocument() const;

// ����
public:

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
	virtual ~Cexp30View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp30View.cpp �еĵ��԰汾
inline Cexp30Doc* Cexp30View::GetDocument() const
   { return reinterpret_cast<Cexp30Doc*>(m_pDocument); }
#endif

