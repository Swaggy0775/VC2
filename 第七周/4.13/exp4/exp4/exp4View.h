
// exp4View.h : Cexp4View ��Ľӿ�
//

#pragma once


class Cexp4View : public CView
{
protected: // �������л�����
	Cexp4View();
	DECLARE_DYNCREATE(Cexp4View)

// ����
public:
	Cexp4Doc* GetDocument() const;

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
	virtual ~Cexp4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Ondlg();
};

#ifndef _DEBUG  // exp4View.cpp �еĵ��԰汾
inline Cexp4Doc* Cexp4View::GetDocument() const
   { return reinterpret_cast<Cexp4Doc*>(m_pDocument); }
#endif

