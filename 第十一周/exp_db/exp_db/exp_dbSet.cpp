
// exp_dbSet.cpp : Cexp_dbSet ���ʵ��
//

#include "stdafx.h"
#include "exp_db.h"
#include "exp_dbSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp_dbSet ʵ��

// ���������� 2020��5��5��, 15:55

IMPLEMENT_DYNAMIC(Cexp_dbSet, CRecordset)

Cexp_dbSet::Cexp_dbSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_F1 = 0.0;
	column1 = L"";
	column2 = 0.0;
	column3 = 0.0;
	column4 = 0.0;
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cexp_dbSet::GetDefaultConnect()
{
	return _T("DSN=db1;DBQ=C:\\Users\\Coisini\\Desktop\\db.xls;DefaultDir=C:\\Users\\Coisini\\Desktop;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString Cexp_dbSet::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void Cexp_dbSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Double(pFX, _T("[F1]"), m_F1);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[ѧ��]"), column2);
	RFX_Double(pFX, _T("[����]"), column3);
	RFX_Double(pFX, _T("[�ֻ�����]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// Cexp_dbSet ���

#ifdef _DEBUG
void Cexp_dbSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cexp_dbSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

