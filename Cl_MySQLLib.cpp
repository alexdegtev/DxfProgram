#include "stdafx.h"
#include "Cl_MySQLLib.h"
using namespace MySQL_SPACE;

MySQL::MySQL() {
	IsConnected = false;
}

MySQL::~MySQL() {

}

bool MySQL::Connect(String ^server, String ^user, String ^password, String ^database, String ^port) {
	String ^connStr = String::Format("server={0};user={1};password={2};database={3};port={4};", server, user, password, database, port);
	connection = gcnew MySqlConnection(connStr);
	try {
		connection->Open();
		shemaName = database;
		IsConnected = true;
		return true;
	}
	catch(String ^ex) {
		return false;
	}
}

void MySQL::Close() {
	if(IsConnected) connection->Close();
}

int MySQL::GetNumRows() {
	cmd = gcnew MySqlCommand("SELECT COUNT(1) FROM " + dbName, connection);
	MySqlDataReader^ rdr = cmd->ExecuteReader();

	rdr->Read();
	int numRows = Convert::ToInt32(Convert::ToString(rdr[0]));
	rdr->Close();
	return numRows;
}

string MySQL::SysToStd(System::String^ SysStr) {
	using namespace Runtime::InteropServices;
	char *v = (char*)(Marshal::StringToHGlobalAnsi(SysStr)).ToPointer();
	std::string result = std::string(v);
	Marshal::FreeHGlobal(System::IntPtr((void*)v));
	return result;
}

int MySQL::Insert(String ^surname, String ^name, String ^patronymic, String ^description, String ^date, String ^time, String ^mini, String ^patchDxf) {
	if(!IsConnected) return -2;
	int res = 0;
	cmd = gcnew MySqlCommand("INSERT INTO " + dbName + " (id, surname, name, patronymic, description, mini, date, time, patch_dxf) VALUES \
		('" + (GetNumRows()+1) + "', '" + surname + "', '" + name + "', '" + patronymic + "', '" + description + "', '" + mini + "', '" + date + "', '" + time + "', '" + patchDxf  + "')", connection);
	res = cmd->ExecuteNonQuery();

	return res;
}

int MySQL::Delete() {
	if(!IsConnected) return -2;
	cmd = gcnew MySqlCommand("DELETE FROM " + dbName + " WHERE `value`='this_value'", connection);
	int res = cmd->ExecuteNonQuery();

	return res;
}

int MySQL::Select(string **result, int *numRows, int *numColls) {
	if(!IsConnected) return -2;
	int i, j;
	int res = 0;
	*numRows = GetNumRows();

	cmd = gcnew MySqlCommand("SELECT * FROM " + dbName, connection);
	MySqlDataReader^ rdr = cmd->ExecuteReader();
	*numColls = rdr->FieldCount;

	result = new string * [*numRows];
	for(i=0; i<*numRows; i++) result[i] = new string [*numColls];
	if(result == NULL) return -3;

	i = j = 0;

	while (rdr->Read()) {
		for(j=0; j<*numColls; j++) result[i][j] = SysToStd(Convert::ToString(rdr[j]));
	}
	rdr->Close();

	return 0;
}