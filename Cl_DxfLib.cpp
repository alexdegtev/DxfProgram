#include "stdafx.h"
#include "Cl_DxfLib.h"

DXF::DXF()	{
	errPointR = 3;
}

DXF::~DXF()	{
	file.close();
}

bool DXF::Open(string dxfFileName) {
	if(file.is_open()) file.close();

	fileName = dxfFileName;
	file.open(fileName);
	LastNumberOfObject = 0;
	EndEntitiesPointer = 0;
	//errPoints.clear();
	Blocks.clear();
	NumBlock = 0;
	SECTION tmp;
	_Section = tmp;

	if(file.is_open()) return true;
	else return false;
}

string DXF::PrintDxf() {
	string line;
	/*while(line != "EOF"){
		file >> line;
		cout << line << endl;
	}*/
	stringstream str;


	if(NumLine) for(int i=0;i<NumLine;i++){
		str << setprecision(20)
			 << "LINE " << i << endl
			 << "number: " << hex << _Section.Entities.Lines[i].number << endl
			 << "x0: " << _Section.Entities.Lines[i].p[0].x << endl
			 << "y0: " << _Section.Entities.Lines[i].p[0].y << endl
			 << "x1: " << _Section.Entities.Lines[i].p[1].x << endl
			 << "y1: " << _Section.Entities.Lines[i].p[1].y << endl
			 << "Layer: " << _Section.Entities.Lines[i].layer << endl
			 << "Type: " << _Section.Entities.Lines[i].type << endl << endl;
	}
	if(NumCircle) for(int i=0;i<NumCircle;i++){
		str << setprecision(20)
			 << "CIRCLE " << i << endl
			 << "number: " << _Section.Entities.Circles[i].number << endl
			 << "x: " << _Section.Entities.Circles[i].p.x << endl
			 << "y: " << _Section.Entities.Circles[i].p.y << endl
			 << "r: " << _Section.Entities.Circles[i].r << endl
			 << "Layer: " << _Section.Entities.Circles[i].layer << endl << endl;
	}
	return str.str();
}

void DXF::ReadLine() {
	string line;
	LINE tmp;
	file >> line >> line;
	LastNumberOfObject = tmp.number = TextToHex(line);
	while(line != "AcDbEntity") file >> line;
	file >> line >> line;
	tmp.layer = line;
	while(line != "AcDbLine") file >> line;
	file >> line >> line;
	tmp.p[0].x = atof(line.c_str());
	file >> line >> line;
	tmp.p[0].y = atof(line.c_str());
	file >> line >> line >> line >> line;
	tmp.p[1].x = atof(line.c_str());
	file >> line >> line;
	tmp.p[1].y = atof(line.c_str());
	tmp.type = 0;
	EndEntitiesPointer = (int)file.tellg();
	_Section.Entities.Lines.push_back(tmp);
}

void DXF::ReadXLine() {
	string line;
	LINE tmp;
	file >> line >> line;
	LastNumberOfObject = tmp.number = TextToHex(line);
	while(line != "AcDbEntity") file >> line;
	file >> line >> line;
	tmp.layer = line;
	while(line != "AcDbLine") file >> line;
	file >> line >> line;
	tmp.p[0].x = atof(line.c_str());
	file >> line >> line;
	tmp.p[0].y = atof(line.c_str());
	file >> line >> line >> line >> line;
	tmp.p[1].x = atof(line.c_str());
	file >> line >> line;
	tmp.p[1].y = atof(line.c_str());
	tmp.type = 1;
	EndEntitiesPointer = (int)file.tellg();
	_Section.Entities.Lines.push_back(tmp);
}

void DXF::ReadCircle() {
	string line;
	CIRCLE tmp;
	file >> line >> line;
	LastNumberOfObject = tmp.number = TextToHex(line);
	while(line != "AcDbEntity") file >> line;
	file >> line >> line;
	tmp.layer = line;
	while(line != "AcDbCircle") file >> line;
	file >> line >> line;
	tmp.p.x = atof(line.c_str());
	file >> line >> line;
	tmp.p.y = atof(line.c_str());
	file >> line >> line >> line >> line;
	tmp.r = atof(line.c_str());
	tmp.current = false;
	EndEntitiesPointer = (int)file.tellg();
	_Section.Entities.Circles.push_back(tmp);
}

void DXF::ReadBlock() {
	string line;
	int blockAddr = (int)file.tellg();
	while(line != "AcDbBlockBegin") file >> line;
	file >> line >> line;
	if(line[0] != 'U') return;

	BLOCK tmp;
	tmp.beginAddr = blockAddr;
	tmp.number = line;
	Blocks.insert(Blocks.end(), tmp);

	while(line != "AcDbBlockEnd") {
		file >> line;
		if(line == "LINE") ReadLine();
	}
}

void DXF::ReadInsert() {
	string line;
	INSERT tmp;
	file >> line >> line;
	LastNumberOfObject = tmp.number = TextToHex(line);
	while(line != "AcDbEntity") file >> line;
	file >> line >> line;
	tmp.layer = line;
	while(line != "AcDbBlockReference") file >> line;
	file >> line >> line;
	tmp.blockNumber = line;
	EndEntitiesPointer = (int)file.tellg();
	_Section.Entities.Inserts.push_back(tmp);
}

void DXF::ReadEllipse() {
	string line;
	ELLIPSE tmp;
	file >> line >> line;
	LastNumberOfObject = tmp.number = TextToHex(line);
	while(line != "AcDbEntity") file >> line;
	file >> line >> line;
	tmp.layer = line;
	while(line != "AcDbEllipse") file >> line;
	file >> line >> line;
	tmp.p.x = atof(line.c_str());
	file >> line >> line;
	tmp.p.y = atof(line.c_str());
	file >> line >> line >> line >> line;
	double endPointMainAxisX = atof(line.c_str());
	file >> line >> line;
	double endPointMainAxisY = atof(line.c_str());
	file >> line >> line >> line >> line >> line;
	file >> line >> line >> line >> line >> line;
	tmp.ratio = atof(line.c_str());

	if(endPointMainAxisY == 0 || abs(endPointMainAxisY) < EPS) {
		tmp.width = abs(endPointMainAxisX);
		tmp.height = tmp.ratio * tmp.width;
		tmp.angle = 0.0;
	}
	else if(abs(endPointMainAxisX) < EPS) {
		tmp.width = abs(endPointMainAxisY);
		tmp.height = tmp.ratio * tmp.width;
		tmp.angle = 90.0;
	}
	else {
		double x0 = tmp.p.x;
		double y0 = tmp.p.y;
		double ax = x0 + endPointMainAxisX;
		double ay = y0 + endPointMainAxisY;
		double a = tmp.width = sqrt(pow(ax - x0, 2) + pow(ay - y0, 2));
		double b = tmp.height = a * tmp.ratio;
		double alpha = acos(abs(ax - x0) / a) * (180 / PI);
		if(endPointMainAxisX < 0 && endPointMainAxisY >= 0) alpha = 180 - alpha;
		if(endPointMainAxisX < 0 && endPointMainAxisY < 0) alpha = 180 + alpha;
		if(endPointMainAxisX >= 0 && endPointMainAxisY < 0) alpha = 360 - alpha;
		tmp.angle = alpha;
	}
	EndEntitiesPointer = (int)file.tellg();
	_Section.Entities.Ellipses.push_back(tmp);
}

void DXF::ReadArc() {
	string line;
	ARC tmp;
	file >> line >> line;
	LastNumberOfObject = tmp.number = TextToHex(line);
	while(line != "AcDbEntity") file >> line;
	file >> line >> line;
	tmp.layer = line;
	while(line != "AcDbCircle") file >> line;
	file >> line >> line;
	tmp.p.x = atof(line.c_str());
	file >> line >> line;
	tmp.p.y = atof(line.c_str());
	file >> line >> line >> line >> line;
	tmp.r = atof(line.c_str());
	file >> line >> line >> line >> line;
	tmp.angleStart = atof(line.c_str());
	file >> line >> line;
	tmp.angleEnd = atof(line.c_str());
	EndEntitiesPointer = (int)file.tellg();
	_Section.Entities.Arcs.push_back(tmp);
}

int DXF::Read() {
	file.seekg(0, ios::beg);
	string line;
	int beginEntitiesPointer = -1;	//Указатель на начало раздела ENTITIES в файле
	
	//Получение указателя на начало раздела "ENTITIES"
	while(line != "EOF") {
		file >> line;
		if(line == "ENTITIES") {
			beginEntitiesPointer = (int)file.tellg();
			break;
		}
	}
	if(beginEntitiesPointer == -1) return 1;

	//Подсчёт количества объектов
	/*while(line != "EOF") {
		file >> line;
		if(line == "POINT") NumPoint++;
		if(line == "LINE") NumLine++;
		if(line == "XLINE") NumLine++;
		if(line == "CIRCLE") NumCircle++;
		if(line == "ELLIPSE") NumEllipse++;
		if(line == "INSERT") NumInsert++;
		if(line == "BLOCK") NumBlock++;
	}*/

	line = "";

	file.seekg(0, ios::beg);
	while(line != "EOF") {
		file >> line;
		if(line == "BLOCK") ReadBlock();
	}
	line = "";
	file.seekg(beginEntitiesPointer);
	
	while(line != "EOF") {
		if(line == "LINE") ReadLine();
		if(line == "XLINE") ReadXLine();
		if(line == "CIRCLE") ReadCircle();
		if(line == "ELLIPSE") ReadEllipse();
		if(line == "INSERT") ReadInsert();
		if(line == "ARC") ReadArc();
		file >> line;
	}
	return 0;
}

bool DXF::Save() {
	saveFileName = "_" + fileName;
	string line;
	
	if(!file.is_open()) return false;
	file.seekg(0, ios::beg);
	saveFile.open(saveFileName);

	bool fl_entities = false;
	while(!file.eof()){
		getline(file, line);
		if(line == "ENTITIES") fl_entities = true;
		if(fl_entities) if(line == "ENDSEC") break;
		saveFile << line << endl;
	}

	if(NumLine) for(int i=0; i<NumLine; i++) saveFile << LineToString(_Section.Entities.Lines[i]);
	if(NumCircle) for(int i=0; i<NumCircle; i++) saveFile << CircleToString(_Section.Entities.Circles[i]);

	saveFile << "ENDSEC\n";

	while(!file.eof()){
		getline(file, line);
		saveFile << line << endl;
	}
	file.close();
	saveFile.close();
	return true;
}

bool DXF::SaveErrorPoints() {
	if(saveFile.is_open()) saveFile.close();
	saveFileName = "_" + fileName;
	string line;

	saveFile.open(saveFileName);
	if(!saveFile.is_open()) return false;

	file.seekg(0, ios::beg);

	bool fl_entities = false;
	while(!file.eof()){
		getline(file, line);
		if(line == "ENTITIES") fl_entities = true;
		if(fl_entities) if(line == "ENDSEC") break;
		saveFile << line << endl;
	}

	/*if(!errPoints.empty()) for(unsigned int i=0; i<errPoints.size(); i++) {
		saveFile << ErrPointToString(errPoints[i]);
	}*/

	saveFile << "ENDSEC\n";

	while(!file.eof()){
		getline(file, line);
		saveFile << line << endl;
	}

	saveFile.close();
	return true;
}

string DXF::LineToString(LINE l) {
	stringstream str;
	str << "LINE\n  5\n" << hex << uppercase << ++LastNumberOfObject << "\n";
	str << "330\n1F\n100\nAcDbEntity\n  8\n" << l.layer << "\n";
	str << "100\nAcDbLine\n";
	str << setprecision(20)
		<< " 10\n" << l.p[0].x + 50 << "\n"
		<< " 20\n" << l.p[0].y + 50 << "\n"
		<< " 30\n0.0\n"
		<< " 11\n" << l.p[1].x + 50 << "\n"
		<< " 21\n" << l.p[1].y + 50 << "\n"
		<< " 31\n0.0\n  0\n";
	return str.str();
}

string DXF::CircleToString(CIRCLE c) {
	stringstream str;
	str << "CIRCLE\n  5\n" << hex << uppercase << ++LastNumberOfObject << "\n";
	str << "330\n1F\n100\nAcDbEntity\n  8\n" << c.layer << "\n";
	str << "100\nAcDbCircle\n";
	str << setprecision(20)
		<< " 10\n" << c.p.x + 50 << "\n"
		<< " 20\n" << c.p.y + 50 << "\n"
		<< " 30\n0.0\n"
		<< " 40\n" << c.r << "\n  0\n";
	return str.str();
}

string DXF::ErrPointToString(POINT p) {
	stringstream str;
	str << "CIRCLE\n  5\n" << hex << uppercase << ++LastNumberOfObject << "\n";
	str << "330\n1F\n100\nAcDbEntity\n  8\n" << /*p.layer*/ "ErrPoints" << "\n";
	str << "100\nAcDbCircle\n";
	str << setprecision(20)
		<< " 10\n" << p.x << "\n"
		<< " 20\n" << p.y << "\n"
		<< " 30\n0.0\n"
		<< " 40\n" << errPointR << "\n  0\n";
	return str.str();
}

int DXF::TextToHex(string str){
	unsigned int i = 1;
	int a = 0;
	while(i <= str.length()){
		int temp = 0;
		switch(str[i-1]){
			case '0': temp = 0; break;
			case '1': temp = 1; break;
			case '2': temp = 2; break;
			case '3': temp = 3; break;
			case '4': temp = 4; break;
			case '5': temp = 5; break;
			case '6': temp = 6; break;
			case '7': temp = 7; break;
			case '8': temp = 8; break;
			case '9': temp = 9; break;
			case 'A':
			case 'a': temp = 0xA; break;
			case 'B':
			case 'b': temp = 0xB; break;
			case 'C':
			case 'c': temp = 0xC; break;
			case 'D':
			case 'd': temp = 0xD; break;
			case 'E':
			case 'e': temp = 0xE; break;
			case 'F':
			case 'f': temp = 0XF; break;
		}
		for(unsigned int j=str.length(); j>i; j--){
			temp *= 16;
		}
		a += temp;
		i++;
	}
	return a;
}
