
// exp1Doc.h : Cexp1Doc 类的接口
//


#pragma once
class  student :public CObject
{
public:
	CString name;
	int age;
	virtual void Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			// TODO: 在此添加存储代码
			ar << name << age;
		}
		else
		{
			// TODO: 在此添加加载代码
			ar >> name >> age;
		}
	}
};

class Cexp1Doc : public CDocument
{
protected: // 仅从序列化创建
	Cexp1Doc();
	DECLARE_DYNCREATE(Cexp1Doc)

// 特性
public:
	CArray <student, student&> m_st;
	CArray <CString, CString&> m_str;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Cexp1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
