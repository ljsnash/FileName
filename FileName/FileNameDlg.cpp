
// FileNameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileName.h"
#include "FileNameDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include"FolderPath.h"
#include"ImportFile.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<io.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileNameDlg �Ի���


IMPLEMENT_DYNAMIC(CFileNameDlg, CDialogEx);

CFileNameDlg::CFileNameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILENAME_DIALOG, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CFileNameDlg::~CFileNameDlg()
{
	// ����öԻ������Զ���������
	//  ���˴���ָ��öԻ���ĺ���ָ������Ϊ NULL���Ա�
	//  �˴���֪���öԻ����ѱ�ɾ����
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CFileNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, edit_Path, m_edit_Path);
	DDX_Control(pDX, btn_Browse, m_btn_Browse);
	DDX_Control(pDX, edit_Path2, m_edit_Path2);
	DDX_Control(pDX, btn_Browse2, m_btn_Browse2);
	DDX_Control(pDX, IDC_RADIO7, m_radio7);
	DDX_Control(pDX, IDC_RADIO9, m_radio9);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, edit_Type, m_edit_Type);
}

BEGIN_MESSAGE_MAP(CFileNameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(edit_Path, &CFileNameDlg::OnEnChangePath)
	ON_BN_CLICKED(IDC_CHECK1, &CFileNameDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(btn_Browse2, &CFileNameDlg::OnBnClickedBrowse2)
	ON_BN_CLICKED(IDOK, &CFileNameDlg::OnBnClickedOk)
	ON_BN_CLICKED(btn_Browse, &CFileNameDlg::OnBnClickedBrowse)
	ON_BN_CLICKED(IDC_RADIO1, &CFileNameDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CFileNameDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO7, &CFileNameDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO9, &CFileNameDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO6, &CFileNameDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO5, &CFileNameDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_CHECK5, &CFileNameDlg::OnBnClickedCheck5)
END_MESSAGE_MAP()


// CFileNameDlg ��Ϣ�������

BOOL CFileNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_RADIO6))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_RADIO7))->SetCheck(1);
	m_edit_Type.EnableWindow(FALSE);
	m_edit_Path.EnableWindow(FALSE);
	m_edit_Path2.EnableWindow(FALSE);
	m_btn_Browse.EnableWindow(FALSE);
	m_btn_Browse2.EnableWindow(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFileNameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFileNameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFileNameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���û��ر� UI ʱ������������Ա���������ĳ��
//  �������Զ�����������Ӧ�˳���  ��Щ
//  ��Ϣ�������ȷ����������: �����������ʹ�ã�
//  ������ UI�������ڹرնԻ���ʱ��
//  �Ի�����Ȼ�ᱣ�������

void CFileNameDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CFileNameDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CFileNameDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CFileNameDlg::CanExit()
{
	// �����������Ա�����������Զ���
	//  �������Իᱣ�ִ�Ӧ�ó���
	//  ʹ�Ի���������������� UI ����������
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void CFileNameDlg::OnEnChangePath()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CFileNameDlg::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	if (i == 1)
	{
		m_check2.EnableWindow(FALSE);
		m_check3.EnableWindow(FALSE);
		m_check4.EnableWindow(FALSE);
		m_check5.EnableWindow(FALSE);
		m_edit_Type.EnableWindow(FALSE);
	}
	else
	{
		m_check2.EnableWindow(TRUE);
		m_check3.EnableWindow(TRUE);
		m_check4.EnableWindow(TRUE);
		m_check5.EnableWindow(TRUE);
		m_edit_Type.EnableWindow(TRUE);
	}

}


void CFileNameDlg::OnBnClickedBrowse2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FolderPath *path = new FolderPath("��ѡ��ѧ����ҵ�����ļ���");
	CString str_FolderPath = path->setFolderPath();
	delete path;
	if (str_FolderPath != "")SetDlgItemText(edit_Path2, str_FolderPath);
}


void CFileNameDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str_path;
	int i;
	i = ((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck();
	if (i == 1)
	{
		str_path = ".";
	}
	else
	{
		GetDlgItemText(edit_Path, str_path);
	}
	//�ļ���λ��
	CString str_path2;
	int j;
	i = ((CButton *)GetDlgItem(IDC_RADIO7))->GetCheck();
	j = ((CButton *)GetDlgItem(IDC_RADIO6))->GetCheck();
	if ((i == 1)||(j==1))
	{
		str_path2 = ".";
	}
	else
	{
		GetDlgItemText(edit_Path2, str_path2);
	}
	//���λ��
	bool behind;
	i = ((CButton *)GetDlgItem(IDC_RADIO4))->GetCheck();
	if (i == 1)
	{
		behind = false;
	}
	else
	{
		behind = true;
	}
	//��׺��
	CString str_file;
	str_file = str_path2 + "\\" + "�ļ���.txt";
	ofstream _file;
	_file.open(str_file, ios::trunc);
	_file.close();
	ImportFile *import = new ImportFile(str_file);
	i = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	if (i == 1)
	{
		import->GetAllFile(str_path, "*", behind);
	}
	else
	{
		if(((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck()==1)
		{ 
			import->GetAllFile(str_path, "caj", behind);
		}
		if (((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck() == 1)
		{
			import->GetAllFile(str_path, "pdf", behind);
		}
		if (((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck() == 1)
		{
			import->GetAllFile(str_path, "doc", behind);
			import->GetAllFile(str_path, "docx", behind);
		}
		CString temp;
		GetDlgItemText(edit_Type, temp);
		while (temp != "")
		{
			int k;
			CString temp2;
			k=temp.Find(";");
			if (k == -1)
			{
				import->GetAllFile(str_path, temp, behind);
				break;
			}
			
			temp2 = temp.Left(k);
			import->GetAllFile(str_path, temp2, behind);
			temp = temp.Mid(k + 1);
		}
	}
	delete import;

	SHELLEXECUTEINFO ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = str_file;
	ShExecInfo.lpParameters = "";
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOW;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	if (j == 1)
	{
		remove(str_file);
	}

}


void CFileNameDlg::OnBnClickedBrowse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FolderPath *path = new FolderPath("��ѡ��ѧ����ҵ�����ļ���");
	CString str_FolderPath = path->setFolderPath();
	delete path;
	if (str_FolderPath != "")SetDlgItemText(edit_Path, str_FolderPath);
}


void CFileNameDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edit_Path.EnableWindow(FALSE);
	m_btn_Browse.EnableWindow(FALSE);
}


void CFileNameDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edit_Path.EnableWindow(TRUE);
	m_btn_Browse.EnableWindow(TRUE);
}


void CFileNameDlg::OnBnClickedRadio7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edit_Path2.EnableWindow(FALSE);
	m_btn_Browse2.EnableWindow(FALSE);
}


void CFileNameDlg::OnBnClickedRadio9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edit_Path2.EnableWindow(TRUE);
	m_btn_Browse2.EnableWindow(TRUE);
}


void CFileNameDlg::OnBnClickedRadio6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_edit_Path2.EnableWindow(FALSE);
	m_btn_Browse2.EnableWindow(FALSE);
	m_radio7.EnableWindow(FALSE);
	m_radio9.EnableWindow(FALSE);
}


void CFileNameDlg::OnBnClickedRadio5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio7.EnableWindow(TRUE);
	m_radio9.EnableWindow(TRUE);
	int i=((CButton *)GetDlgItem(IDC_RADIO7))->GetCheck();
	if (i == 1)
	{
		m_edit_Path2.EnableWindow(FALSE);
		m_btn_Browse2.EnableWindow(FALSE);
	}
	else
	{
		m_edit_Path2.EnableWindow(TRUE);
		m_btn_Browse2.EnableWindow(TRUE);		
	}
	
}


void CFileNameDlg::OnBnClickedCheck5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i = ((CButton *)GetDlgItem(IDC_CHECK5))->GetCheck();
	if (i == 1)
	{
		m_edit_Type.EnableWindow(TRUE);
	}
	else
	{
		m_edit_Type.EnableWindow(FALSE);
	}
}
