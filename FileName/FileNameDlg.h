
// FileNameDlg.h : 头文件
//

#pragma once

class CFileNameDlgAutoProxy;


// CFileNameDlg 对话框
class CFileNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFileNameDlg);
	friend class CFileNameDlgAutoProxy;

// 构造
public:
	CFileNameDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CFileNameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILENAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CFileNameDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
