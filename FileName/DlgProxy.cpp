
// DlgProxy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileName.h"
#include "DlgProxy.h"
#include "FileNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileNameDlgAutoProxy

IMPLEMENT_DYNCREATE(CFileNameDlgAutoProxy, CCmdTarget)

CFileNameDlgAutoProxy::CFileNameDlgAutoProxy()
{
	EnableAutomation();
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ���  ���ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CFileNameDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFileNameDlg)))
		{
			m_pDialog = reinterpret_cast<CFileNameDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CFileNameDlgAutoProxy::~CFileNameDlgAutoProxy()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	//	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CFileNameDlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CFileNameDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFileNameDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_IFileName ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {5C1DE705-C397-44B1-A140-2947147D6EBA}
static const IID IID_IFileName =
{ 0x5C1DE705, 0xC397, 0x44B1, { 0xA1, 0x40, 0x29, 0x47, 0x14, 0x7D, 0x6E, 0xBA } };

BEGIN_INTERFACE_MAP(CFileNameDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CFileNameDlgAutoProxy, IID_IFileName, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {1BDDFF32-E9C1-478C-A710-B8DA6AD43D3C}
IMPLEMENT_OLECREATE2(CFileNameDlgAutoProxy, "FileName.Application", 0x1bddff32, 0xe9c1, 0x478c, 0xa7, 0x10, 0xb8, 0xda, 0x6a, 0xd4, 0x3d, 0x3c)


// CFileNameDlgAutoProxy ��Ϣ�������
