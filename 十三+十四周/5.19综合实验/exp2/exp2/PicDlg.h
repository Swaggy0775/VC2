#pragma once


// PicDlg �Ի���

class PicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PicDlg)

public:
	PicDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PicDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	CString path;
	void PicDlg::draw();
	afx_msg void OnPaint();
};
