
// exp3View.h : Cexp3View ��Ľӿ�
//

#pragma once


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

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

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
};

#ifndef _DEBUG  // exp3View.cpp �еĵ��԰汾
inline Cexp3Doc* Cexp3View::GetDocument() const
   { return reinterpret_cast<Cexp3Doc*>(m_pDocument); }
#endif

