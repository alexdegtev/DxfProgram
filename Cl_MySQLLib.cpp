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
	cmd = gcnew MySqlCommand("SELECT COUNT(1) FROM `" + dbName1 + "`", connection);
	MySqlDataReader^ rdr = cmd->ExecuteReader();

	rdr->Read();
	int numRows = Convert::ToInt32(rdr[0]->ToString());
	rdr->Close();
	return numRows;
}

string MySQL::SysToStd(String^ SysStr) {
	char *v = (char*)(Marshal::StringToHGlobalAnsi(SysStr)).ToPointer();
	std::string result = std::string(v);
	Marshal::FreeHGlobal(System::IntPtr((void*)v));
	return result;
}

/*System::String ^MySQL::AddSlashes(System::String ^InputTxt) {
    // List of characters handled:
    // \000 null
    // \010 backspace
    // \011 horizontal tab
    // \012 new line
    // \015 carriage return
    // \032 substitute
    // \042 double quote
    // \047 single quote
    // \134 backslash
    // \140 grave accent

    System::String ^Result = InputTxt;

    try
    {
        Result = System::Text::RegularExpressions::Regex::Replace(InputTxt, "[\\000\\010\\011\\012\\015\\032\\042\\047\\134\\140]", "\\$0");
    }
    catch (Exception ^Ex)
    {
        // handle any exception here
        Console::WriteLine(Ex->Message);
    }

    return Result;
}*/

/*int MySQL::Insert(String ^surname, String ^name, String ^patronymic, String ^description, String ^date, String ^time, String ^mini, String ^patchDxf) {
	if(!IsConnected) return -2;
	int res = 0;

	FILE* file1;
	file1 = fopen("D:\\tiger.jpg", "rb");

	//получение размера файла
	fseek(file1, 0, SEEK_END);
	long size = ftell(file1);
	fseek(file1, 0, SEEK_SET);

	//Чтение файла
	string pic = "";
	for(int i=0; i<size; i++) pic += fgetc(file1);

	String ^tmp = gcnew System::String(pic.c_str());
	tmp = AddSlashes(tmp);

	//INSERT INTO table SET fblob=LOAD_FILE("image.gif")
	//cmd = gcnew MySqlCommand("INSERT INTO mini `minicol` VALUES '" + tmp + "'", connection);
	//res = cmd->ExecuteNonQuery();
	

	cmd = gcnew MySqlCommand("INSERT INTO " + dbName1 + " (id, surname, name, patronymic, description, mini, date, time, patch_dxf) VALUES \
		('" + (GetNumRows()+1) + "', '" + surname + "', '" + name + "', '" + patronymic + "', '" + description + "', '" + tmp + "', '" + date + "', '" + time + "', '" + patchDxf  + "')", connection);
	res = cmd->ExecuteNonQuery();

	return res;
}*/

int MySQL::Insert(String ^s1, String ^s2, String ^s3, String ^s4, String ^s5, String ^s6, String ^s7, String ^s8, String ^s9, String ^s10,
			   String ^s11, String ^s12, String ^s13, String ^s14, String ^s15, String ^s16, String ^s17, String ^filePath) {
	if(!IsConnected) return -2;
	int res = 0;

	String ^StrCom = String::Format("INSERT INTO `" + dbName1 + "` (`наименование изделия`, `наименование документа`, `обозначение документа`, `код документа`, `характер работы выполнемый лицом,подписывающий документ`, \
			`фамилия лица,подписывающего документ`, `подпись лица,подписывающего документ`, `дата подписания документа`, `подпись лица,принявшего подлинник`, `дата приемки`, `подпись лица,принявшего дубликат`, \
			`дата приемки дубликата`, `номер решения об утверждении документации`, `год утверждения документации`, `подпись должностного лица`, `расшифровка подписи`, `дата визирования`) VALUES \
			('{0}', '{1}', '{2}', '{3}', '{4}', '{5}', '{6}', '{7}', '{8}', '{9}', '{10}', '{11}', '{12}', {13}, '{14}', '{15}', '{16}')",
			s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
	cmd = gcnew MySqlCommand(StrCom, connection);
	res = cmd->ExecuteNonQuery();

	StrCom = String::Format("INSERT INTO `" + dbName2 + "` (`ссылка на чертеж`) VALUES ('{0}')", filePath);
	cmd = gcnew MySqlCommand(StrCom, connection);
	res = cmd->ExecuteNonQuery();

	return res;
}

int MySQL::Insert(String ^s1, String ^s2, String ^s3, String ^s4, String ^s5, String ^s6, String ^filePath) {
	if(!IsConnected) return -2;
	int res = 0;

	String ^StrCom = String::Format("INSERT INTO `" + dbName2 + "` (`порядковый номер изменения`, `указания об изменении листа`, `номер документа на основании которого производятся измнения`, \
			`подпись лица,внесшего изменеия`, `дата внесения изменения`, `ссылка на чертеж`) VALUES ('{0}', '{1}', '{2}', '{3}', '{4}', '{5}')", s2, s3, s4, s5, s6, filePath);
	cmd = gcnew MySqlCommand(StrCom, connection);
	res = cmd->ExecuteNonQuery();

	return res;
}

int MySQL::Delete() {
	if(!IsConnected) return -2;
	cmd = gcnew MySqlCommand("DELETE FROM " + dbName1 + " WHERE `value`='this_value'", connection);
	int res = cmd->ExecuteNonQuery();

	return res;
}

int MySQL::Select(String ^fild, string *result) {
	if(result == NULL) return -3;
	if(!IsConnected) return -2;
	int i;
	int res = 0;

	cmd = gcnew MySqlCommand("SELECT `" + fild + "` FROM `" + dbName1 + "`", connection);
	MySqlDataReader^ rdr = cmd->ExecuteReader();

	i = 0;

	while(rdr->Read()) {
		result[i] = SysToStd(rdr[0]->ToString());
		i++;
	}
	rdr->Close();

	return 0;
}

/*int MySQL::Select(string **result, int *numRows, int *numColls) {
	if(!IsConnected) return -2;
	int i, j;
	int res = 0;
	*numRows = GetNumRows();

	cmd = gcnew MySqlCommand("SELECT * FROM " + dbName1, connection);
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
}*/