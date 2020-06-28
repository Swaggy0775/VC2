
// exp1Set.cpp : Cexp1Set ���ʵ��
//

#include "stdafx.h"
#include "exp1.h"
#include "exp1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1Set ʵ��

// ���������� 2020��5��12��, 14:58

IMPLEMENT_DYNAMIC(Cexp1Set, CRecordset)

Cexp1Set::Cexp1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cexp1Set::GetDefaultConnect()
{
	return _T("DSN=sdb;DBQ=C:\\Users\\Coisini\\Desktop\\\x5b66\x751f\x4fe1\x606f.xls;DefaultDir=C:\\Users\\Coisini\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString Cexp1Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void Cexp1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[�ļ�·��]"), column2);

}
/////////////////////////////////////////////////////////////////////////////
// Cexp1Set ���

#ifdef _DEBUG
void Cexp1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cexp1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

