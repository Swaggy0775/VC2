
// exp_dbDoc.h : Cexp_dbDoc ��Ľӿ�
//


#pragma once
#include "exp_dbSet.h"


class Cexp_dbDoc : public CDocument
{
protected: // �������л�����
	Cexp_dbDoc();
	DECLARE_DYNCREATE(Cexp_dbDoc)

// ����
public:
	Cexp_dbSet m_exp_dbSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cexp_dbDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
