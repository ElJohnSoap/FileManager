
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
#include <direct.h>
#include "folder.h"
using namespace std;

//const char* StringToChar(string s)
//{
//	const char* c = s.c_str();
//	return c;
//}

int main()
{
	/*string path = "C:\\Users\\avs\\source\\repos\\*";
	const char* cPath = path.c_str();*/
	//cout << cPath;
	/*Folder s;
	s.showAll(path);*/


		//�������� ���� (��������, ����� Temp �� ����� C, 
		//��������� ����� ��� �������: c:\temp\)
		char path[70];
		cout << "\nEnter full path (for example, C:\\):";
		cin >> path;
		//�������� ����� ������
		char mask[15];
		cout << "\nEnter mask (for example, *.* or *.txt):";
		cin >> mask;
		//�������� ��� ������, �� ������� ���������
		//�.�. ��� ����� ����� ������������ � ��� 
		strcat(path, mask);

			//���������� ��������� fileinfo 
			//�� ��������� _finddata_t
			//� �������� ������������� ������� 
			//��������� _finddata_t
			_finddata_t * fileinfo = new _finddata_t;
		//�������� �����
		long done = _findfirst(path, fileinfo);
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

