
// exp2Doc.h : Cexp2Doc ��Ľӿ�
//


#pragma once
#include "atltypes.h"


class Cexp2Doc : public CDocument
{
protected: // �������л�����
	Cexp2Doc();
	DECLARE_DYNCREATE(Cexp2Doc)

// ����
public:

// ����
public:
	bool set = true;
	int r = 20;
	CArray <int, int >m_color;
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
	virtual ~Cexp2Doc();
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
	CPoint mid;
	int color=20;
};
