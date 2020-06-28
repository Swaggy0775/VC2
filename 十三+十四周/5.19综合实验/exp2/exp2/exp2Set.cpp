
// exp2Set.cpp : Cexp2Set ���ʵ��
//

#include "stdafx.h"
#include "exp2.h"
#include "exp2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp2Set ʵ��

// ���������� 2020��5��26��, 14:56

IMPLEMENT_DYNAMIC(Cexp2Set, CRecordset)

Cexp2Set::Cexp2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = 0;
	column5 = 0;
	column6 = L"";
	column7 = L"";
	column8 = L"";
	column9 = L"";
	column10 = L"";
	m_nFields = 10;
	//m_nDefaultType = snapshot;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cexp2Set::GetDefaultConnect()
{
	return _T("DSN=d5;DBQ=C:\\Users\\Coisini\\Desktop\\d5.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cexp2Set::GetDefaultSQL()
{
	return _T("[��1]");
}

void Cexp2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[·��]"), column3);
	RFX_Long(pFX, _T("[����]"), column4);
	RFX_Long(pFX, _T("[нˮ]"), column5);
	RFX_Text(pFX, _T("[רҵ]"), column6);
	RFX_Text(pFX, _T("[�Ա�]"), column7);
	RFX_Text(pFX, _T("[����]"), column8);
	RFX_Text(pFX, _T("[�ֻ���]"), column9);
	RFX_Text(pFX, _T("[סַ]"), column10);
}
/////////////////////////////////////////////////////////////////////////////
// Cexp2Set ���

#ifdef _DEBUG
void Cexp2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cexp2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

