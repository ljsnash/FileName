
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class CFileNameDlg;


// CFileNameDlgAutoProxy ����Ŀ��

class CFileNameDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CFileNameDlgAutoProxy)

	CFileNameDlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	CFileNameDlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~CFileNameDlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CFileNameDlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

