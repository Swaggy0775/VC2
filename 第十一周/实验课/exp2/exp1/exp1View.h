
// exp1View.h : Cexp1View ��Ľӿ�
//

#pragma once
#include "afxwin.h"

class Cexp1Set;

class Cexp1View : public CRecordView
{
protected: // �������л�����
	Cexp1View();
	DECLARE_DYNCREATE(Cexp1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EXP1_FORM };
#endif
	Cexp1Set* m_pSet;

// ����
public:
	Cexp1Doc* GetDocument() const;
	void Cexp1View::drawimg(CString s);
// ����
public:

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
	virtual ~Cexp1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CRect rect;
//	CString Name;
//	CString filePath;
	afx_msg void OnBnClickedPic();
	afx_msg void OnPaint();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
};

#ifndef _DEBUG  // exp1View.cpp �еĵ��԰汾
inline Cexp1Doc* Cexp1View::GetDocument() const
   { return reinterpret_cast<Cexp1Doc*>(m_pDocument); }
#endif

