
// exp30Doc.h : Cexp30Doc ��Ľӿ�
//


#pragma once
#include "atltypes.h"


class Cexp30Doc : public CDocument
{
protected: // �������л�����
	Cexp30Doc();
	DECLARE_DYNCREATE(Cexp30Doc)

// ����
public:

// ����
public:
	int N;
	CArray <CRect, CRect> cr;
	bool set;
	CArray <bool, bool> set2;

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cexp30Doc();
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
public:
	// ����������־// ����������־
//	bool set2;
};
