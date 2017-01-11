
// FileNameDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

class CFileNameDlgAutoProxy;


// CFileNameDlg �Ի���
class CFileNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFileNameDlg);
	friend class CFileNameDlgAutoProxy;

// ����
public:
	CFileNameDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CFileNameDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILENAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	CFileNameDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
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
