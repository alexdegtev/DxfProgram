#ifndef CL_MYSQLLIB_H
#define CL_MYSQLLIB_H

#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

namespace MySQL_SPACE {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace MySql::Data::MySqlClient;
	using namespace Runtime::InteropServices;

	ref class MySQL {
	private:
		bool IsConnected;	//frue - подключено к БД, false - не подключено
		MySqlConnection ^connection;	//Переменная БД
		MySqlCommand ^cmd;	//Переменная для передачи запросов в БД
		String ^shemaName;	//Имя схемы
		
	public:
		String ^dbName1;	//Имя первой базы данных
		String ^dbName2;	//Имя второй базы данных
		int GetNumRows();	//Возвращает количество строк из первой БД
		string SysToStd(System::String^ SysStr);	//System::String в std::string

		MySQL();
		~MySQL();
		bool Connect(String ^server, String ^user, String ^password, String ^database, String ^port);
		void Close();
		int Insert(String ^s1, String ^s2, String ^s3, String ^s4, String ^s5, String ^s6, String ^s7, String ^s8, String ^s9, String ^s10,
			   String ^s11, String ^s12, String ^s13, String ^s14, String ^s15, String ^s16, String ^s17, String ^filePath);	//Запись в первую БД. Возвращает кол-во обработанных строк(>= 0), -1 при ошибке обратотки, -2 при отсутствии установленного соединения с базой данных
		int Insert(String ^s1, String ^s2, String ^s3, String ^s4, String ^s5, String ^s6, String ^filePath);	//Запись во вторую БД. Возвращает кол-во обработанных строк(>= 0), -1 при ошибке обратотки, -2 при отсутствии установленного соединения с базой данных
		int Delete();	//Удаляет из первой БД. Возвращает кол-во обработанных строк(>= 0), -1 при ошибке обратотки, -2 при отсутствии установленного соединения с базой данных
		//int Select(string **result, int *numRows, int *numColls);
		int Select(String ^fild, string *result);	//В result возвращает все строки таблицы
		//String ^AddSlashes(String ^InputTxt);
	};
}
#endif