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
	//если done будет равняться -1,
	//то поиск вести бесмысленно
	int MayWeWork = done;
	//Счетчик, содержит информацию о количестве
	//найденых файлов.
	int count = 0;
	while (MayWeWork != -1)
	{
		count++;
		//Распечатали имя найденного файла
		cout << fileinfo->name << "\n\n";
		//Пытаемся найти следующий файл из группы
		MayWeWork = _findnext(done, fileinfo);
	}
	//Вывод сообщения о количестве найденных файлов. 
	cout << "\nInformation: was found " << count;
	cout << " file(s) in folder..." << path << "\n\n";
	//Очистка памяти
	_findclose(done);
	delete fileinfo;			
	}

};

