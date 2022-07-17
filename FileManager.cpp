
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


		//Запросим ПУТЬ (например, папка Temp на диске C, 
		//запишется таким вот образом: c:\temp\)
		char path[70];
		cout << "\nEnter full path (for example, C:\\):";
		cin >> path;
		//Запросим маску файлов
		char mask[15];
		cout << "\nEnter mask (for example, *.* or *.txt):";
		cin >> mask;
		//Соединив две строки, мы получим результат
		//т.е. что хочет найти пользователь и где 
		strcat(path, mask);

			//Объявление указателя fileinfo 
			//на структуру _finddata_t
			//и создание динамического объекта 
			//структуры _finddata_t
			_finddata_t * fileinfo = new _finddata_t;
		//Начинаем поиск
		long done = _findfirst(path, fileinfo);
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

