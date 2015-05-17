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

	ref class MySQL {
	private:
		bool IsConnected;
		MySqlConnection ^connection;
		MySqlCommand ^cmd;
		int nextTime;
		IAsyncResult ^asyncResult;
		DateTime start;
		String ^shemaName;
		int GetNumRows();
		string SysToStd(System::String^ SysStr);
	public:
		String ^dbName;

		MySQL();
		~MySQL();
		bool Connect(String ^server, String ^user, String ^password, String ^database, String ^port);
		void Close();
		int Insert(String ^surname, String ^name, String ^patronymic, String ^description, String ^date, String ^time, String ^mini);	//���������� ���-�� ������������ �����(>= 0), -1 ��� ������ ���������, -2 ��� ���������� �������������� ���������� � ����� ������
		int Delete();	//���������� ���-�� ������������ �����(>= 0), -1 ��� ������ ���������, -2 ��� ���������� �������������� ���������� � ����� ������
		int Select(string **result, int *numRows, int *numColls);
	};
}
#endif