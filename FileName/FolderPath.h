#pragma once
#include<iostream>
#include<string>
#include<afxwin.h>


using namespace std;

class FolderPath {
public:
	FolderPath(CString str_title)
	{
		char ch[MAX_PATH];     //存放选择的目录路径 
		ZeroMemory(ch, sizeof(ch));
		bi.hwndOwner = NULL;
		bi.pidlRoot = NULL;
		bi.pszDisplayName = ch;
		bi.lpszTitle = str_title;
		bi.ulFlags = 0;
		bi.lpfn = NULL;
		bi.lParam = 0;
		bi.iImage = 0;
		//弹出选择目录对话框
		LPITEMIDLIST lp = SHBrowseForFolder(&bi);
		SHGetPathFromIDList(lp, ch);
		str.Format(ch);
	}

	CString setFolderPath()
	{
		return str;
	}
private:
	char ch[MAX_PATH];     //存放选择的目录路径 
	CString str;
	BROWSEINFO bi;

};