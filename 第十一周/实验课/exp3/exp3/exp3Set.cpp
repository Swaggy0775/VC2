
// exp3Set.cpp : Cexp3Set 类的实现
//

#include "stdafx.h"
#include "exp3.h"
#include "exp3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp3Set 实现

// 代码生成在 2020年5月18日, 15:31

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
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[名字]"), column1);
	RFX_Text(pFX, _T("[文件路径]"),column2);
	RFX_Double(pFX, _T("[年龄]"),column3);

}
/////////////////////////////////////////////////////////////////////////////
// Cexp3Set 诊断

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

