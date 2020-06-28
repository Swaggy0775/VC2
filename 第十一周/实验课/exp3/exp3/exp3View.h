
// exp3View.h : Cexp3View ��Ľӿ�
//

#pragma once

class Cexp3Set;

class Cexp3View : public CRecordView
{
protected: // �������л�����
	Cexp3View();
	DECLARE_DYNCREATE(Cexp3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EXP3_FORM };
#endif
	Cexp3Set* m_pSet;

// ����
public:
	Cexp3Doc* GetDocument() const;

// ����
public:
	CRect rect;
	CString nowPath;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
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
	afx_msg void OnRecordNext();
	afx_msg void OnPaint();
	afx_msg void Onbigshow();
	afx_msg void OnRecordPrev();
};

#ifndef _DEBUG  // exp3View.cpp �еĵ��԰汾
inline Cexp3Doc* Cexp3View::GetDocument() const
   { return reinterpret_cast<Cexp3Doc*>(m_pDocument); }
#endif

