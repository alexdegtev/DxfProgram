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
		bool IsConnected;	//frue - ���������� � ��, false - �� ����������
		MySqlConnection ^connection;	//���������� ��
		MySqlCommand ^cmd;	//���������� ��� �������� �������� � ��
		String ^shemaName;	//��� �����
		
	public:
		String ^dbName1;	//��� ������ ���� ������
		String ^dbName2;	//��� ������ ���� ������
		int GetNumRows();	//���������� ���������� ����� �� ������ ��
		string SysToStd(System::String^ SysStr);	//System::String � std::string

		MySQL();
		~MySQL();
		bool Connect(String ^server, String ^user, String ^password, String ^database, String ^port);
		void Close();
		int Insert(String ^s1, String ^s2, String ^s3, String ^s4, String ^s5, String ^s6, String ^s7, String ^s8, String ^s9, String ^s10,
			   String ^s11, String ^s12, String ^s13, String ^s14, String ^s15, String ^s16, String ^s17, String ^filePath);	//������ � ������ ��. ���������� ���-�� ������������ �����(>= 0), -1 ��� ������ ���������, -2 ��� ���������� �������������� ���������� � ����� ������
		int Insert(String ^s1, String ^s2, String ^s3, String ^s4, String ^s5, String ^s6, String ^filePath);	//������ �� ������ ��. ���������� ���-�� ������������ �����(>= 0), -1 ��� ������ ���������, -2 ��� ���������� �������������� ���������� � ����� ������
		int Delete();	//������� �� ������ ��. ���������� ���-�� ������������ �����(>= 0), -1 ��� ������ ���������, -2 ��� ���������� �������������� ���������� � ����� ������
		//int Select(string **result, int *numRows, int *numColls);
		int Select(String ^fild, string *result);	//� result ���������� ��� ������ �������
		//String ^AddSlashes(String ^InputTxt);
	};
}
#endif