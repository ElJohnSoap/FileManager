#pragma once
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
#include <direct.h>
#include "folder.h"
using namespace std;

class Folder

{
private:
	string currentDirectory;

public:
	
	

	Folder(string currentDirectory_) : currentDirectory{currentDirectory_} {}
	Folder() : Folder("C:\\"){}
	

	
	void showAll(string path)
	{
	
	const char* cPath = path.c_str();
	cout << cPath;
	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst(cPath, fileinfo);
	//���� done ����� ��������� -1,
	//�� ����� ����� �����������
	int MayWeWork = done;
	//�������, �������� ���������� � ����������
	//�������� ������.
	int count = 0;
	while (MayWeWork != -1)
	{
		count++;
		//����������� ��� ���������� �����
		cout << fileinfo->name << "\n\n";
		//�������� ����� ��������� ���� �� ������
		MayWeWork = _findnext(done, fileinfo);
	}
	//����� ��������� � ���������� ��������� ������. 
	cout << "\nInformation: was found " << count;
	cout << " file(s) in folder..." << path << "\n\n";
	//������� ������
	_findclose(done);
	delete fileinfo;			
	}

};

