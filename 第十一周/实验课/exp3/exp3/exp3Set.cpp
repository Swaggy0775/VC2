
// exp3Set.cpp : Cexp3Set ���ʵ��
//

#include "stdafx.h"
#include "exp3.h"
#include "exp3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp3Set ʵ��

// ���������� 2020��5��18��, 15:31

IMPLEMENT_DYNAMIC(Cexp3Set, CRecordset)

Cexp3Set::Cexp3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = L"";
	column3 = 0.0;
	m_nFields = 3;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cexp3Set::GetDefaultConnect()
{
	return _T("DSN=sdb;DBQ=C:\\Users\\Coisini\\Desktop\\\x5b66\x751f\x4fe1\x606f.xls;DefaultDir=C:\\Users\\Coisini\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString Cexp3Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void Cexp3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[�ļ�·��]"),column2);
	RFX_Double(pFX, _T("[����]"),column3);

}
/////////////////////////////////////////////////////////////////////////////
// Cexp3Set ���

#ifdef _DEBUG
void Cexp3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cexp3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

