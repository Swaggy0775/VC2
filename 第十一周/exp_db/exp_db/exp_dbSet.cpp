
// exp_dbSet.cpp : Cexp_dbSet 类的实现
//

#include "stdafx.h"
#include "exp_db.h"
#include "exp_dbSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp_dbSet 实现

// 代码生成在 2020年5月5日, 15:55

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
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Double(pFX, _T("[F1]"), m_F1);
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Double(pFX, _T("[学号]"), column2);
	RFX_Double(pFX, _T("[年龄]"), column3);
	RFX_Double(pFX, _T("[手机号码]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// Cexp_dbSet 诊断

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

