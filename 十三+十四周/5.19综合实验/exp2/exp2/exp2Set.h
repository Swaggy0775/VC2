
// exp2Set.h: Cexp2Set ��Ľӿ�
//


#pragma once

// ���������� 2020��5��26��, 14:56

class Cexp2Set : public CRecordset
{
public:
	Cexp2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cexp2Set)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	column1;
	CStringW	column2;
	CStringW	column3;
	long	column4;
	long	column5;
	CStringW	column6;
	CStringW	column7;
	CStringW	column8;
	CStringW	column9;
	CStringW	column10;
// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

