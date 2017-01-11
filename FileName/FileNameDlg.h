
// FileNameDlg.h : ͷ�ļ�
//

#pragma once

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
};
