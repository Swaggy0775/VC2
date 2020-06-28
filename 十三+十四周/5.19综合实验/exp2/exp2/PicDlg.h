#pragma once


// PicDlg 对话框

class PicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PicDlg)

public:
	PicDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PicDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	CString path;
	void PicDlg::draw();
	afx_msg void OnPaint();
};
