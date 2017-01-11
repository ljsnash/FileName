#pragma once
#include "stdafx.h"
#include "FileName.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include<io.h>
#include<iostream>
#include<stdlib.h>
#include <fstream>  
using namespace std;

class ImportFile
{
public:
	ImportFile(CString _file)
	{
		file.open(_file,ios::app);
	}
	~ImportFile()
	{
		file.close();
	}
	void GetFirstFile(CString folder, CString _type,bool behind=false)
	{
		_type = "*." + _type;
		CString _folder = folder + "\\" + _type;
		handle = _findfirst(_folder, &fileinfo);
		if (handle != -1)
		{
			CString FileName;
			if (behind == false)
			{
				CString temp = fileinfo.name;
				int i = temp.Find(".");
				FileName = temp.Left(i);
			}
			else
			{
				FileName = fileinfo.name;
			}
			if (FileName != "文件名.txt")
			{
				file << FileName << endl;
			}
		}
	}
	void GetAllFile(CString folder,CString _type,bool behind=false)
	{
		GetFirstFile(folder,_type,behind);
		if (handle != -1)
		{
			while (!_findnext(handle, &fileinfo))
			{
				CString FileName;
				if (behind == false)
				{
					CString temp = fileinfo.name;
					int i = temp.Find(".");
					FileName = temp.Left(i);
				}
				else
				{
					FileName = fileinfo.name;
				}
				if (FileName != "文件名.txt")
				{
					file << FileName << endl;
				}
			}
		}
		_findclose(handle);
	}
private:
	intptr_t handle = -1;
	struct _finddata_t fileinfo;
	CString type;
	ofstream file;
};
