
// exp1Set.cpp : Cexp1Set 类的实现
//

#include "stdafx.h"
#include "exp1.h"
#include "exp1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1Set 实现

// 代码生成在 2020年5月12日, 14:58

IMPLEMENT_DYNAMIC(Cexp1Set, CRecordset)

Cexp1Set::Cexp1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[名字]"), column1);
	RFX_Text(pFX, _T("[文件路径]"), column2);

}
/////////////////////////////////////////////////////////////////////////////
// Cexp1Set 诊断

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

