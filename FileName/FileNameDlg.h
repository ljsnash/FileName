
// FileNameDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

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
public:
	afx_msg void OnEnChangePath();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedBrowse2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBrowse();
	afx_msg void OnBnClickedRadio1();
	CEdit m_edit_Path;
	CButton m_btn_Browse;
	afx_msg void OnBnClickedRadio2();
	CEdit m_edit_Path2;
	CButton m_btn_Browse2;
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio6();
	CButton m_radio7;
	CButton m_radio9;
	afx_msg void OnBnClickedRadio5();
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
	CEdit m_edit_Type;
	afx_msg void OnBnClickedCheck5();
};
