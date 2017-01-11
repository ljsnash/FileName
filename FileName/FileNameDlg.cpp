
// FileNameDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CFileNameDlg 对话框


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
	// 如果该对话框有自动化代理，则
	//  将此代理指向该对话框的后向指针设置为 NULL，以便
	//  此代理知道该对话框已被删除。
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


// CFileNameDlg 消息处理程序

BOOL CFileNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFileNameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFileNameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

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
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void CFileNameDlg::OnEnChangePath()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CFileNameDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	FolderPath *path = new FolderPath("请选择学生作业所在文件夹");
	CString str_FolderPath = path->setFolderPath();
	delete path;
	if (str_FolderPath != "")SetDlgItemText(edit_Path2, str_FolderPath);
}


void CFileNameDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
	//文件夹位置
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
	//输出位置
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
	//后缀名
	CString str_file;
	str_file = str_path2 + "\\" + "文件名.txt";
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
	// TODO: 在此添加控件通知处理程序代码
	FolderPath *path = new FolderPath("请选择学生作业所在文件夹");
	CString str_FolderPath = path->setFolderPath();
	delete path;
	if (str_FolderPath != "")SetDlgItemText(edit_Path, str_FolderPath);
}


void CFileNameDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit_Path.EnableWindow(FALSE);
	m_btn_Browse.EnableWindow(FALSE);
}


void CFileNameDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit_Path.EnableWindow(TRUE);
	m_btn_Browse.EnableWindow(TRUE);
}


void CFileNameDlg::OnBnClickedRadio7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit_Path2.EnableWindow(FALSE);
	m_btn_Browse2.EnableWindow(FALSE);
}


void CFileNameDlg::OnBnClickedRadio9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit_Path2.EnableWindow(TRUE);
	m_btn_Browse2.EnableWindow(TRUE);
}


void CFileNameDlg::OnBnClickedRadio6()
{
	// TODO: 在此添加控件通知处理程序代码

	m_edit_Path2.EnableWindow(FALSE);
	m_btn_Browse2.EnableWindow(FALSE);
	m_radio7.EnableWindow(FALSE);
	m_radio9.EnableWindow(FALSE);
}


void CFileNameDlg::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
