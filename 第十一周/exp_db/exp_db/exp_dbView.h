
// exp_dbView.h : Cexp_dbView ��Ľӿ�
//

#pragma once

class Cexp_dbSet;

class Cexp_dbView : public CRecordView
{
protected: // �������л�����
	Cexp_dbView();
	DECLARE_DYNCREATE(Cexp_dbView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EXP_DB_FORM };
#endif
	Cexp_dbSet* m_pSet;

// ����
public:
	Cexp_dbDoc* GetDocument() const;

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
	virtual ~Cexp_dbView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	double ID;
	CString name;
	CString sno;
	double age;
	double phone;
};

#ifndef _DEBUG  // exp_dbView.cpp �еĵ��԰汾
inline Cexp_dbDoc* Cexp_dbView::GetDocument() const
   { return reinterpret_cast<Cexp_dbDoc*>(m_pDocument); }
#endif

