
// exp2View.h : Cexp2View ��Ľӿ�
//

#pragma once

class Cexp2Set;

class Cexp2View : public CRecordView
{
protected: // �������л�����
	Cexp2View();
	DECLARE_DYNCREATE(Cexp2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EXP2_FORM };
#endif
	Cexp2Set* m_pSet;

// ����
public:
	Cexp2Doc* GetDocument() const;

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
	CRect rect;
	CString Name;
	CString Sno;
	int Age;
	afx_msg void OnQuery();
	afx_msg void OnSort();
	afx_msg void OnRestore();
	afx_msg void OnTraver();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnModifi();
	int Salary;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	CString prof;
	CString Sex;
	CString Birthday;
	CString telephone;
	afx_msg void OnShowPic();
	CString Address;
	afx_msg void OnEnChangeEdit8();
};

#ifndef _DEBUG  // exp2View.cpp �еĵ��԰汾
inline Cexp2Doc* Cexp2View::GetDocument() const
   { return reinterpret_cast<Cexp2Doc*>(m_pDocument); }
#endif

