#ifndef CL_DXFLIB_H
#define CL_DXFLIB_H

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

#define EPS 1e-9
#define PI 3.1415926535
#define ErrorLayerName "ErrorsLayer"

struct POINT {
	double x;
	double y;
	unsigned short int type;
	string layer;
	int number;
};

struct LINE {
	POINT p[2];
	unsigned short int type;	//0 - LINE, 1 - XLINE
	string layer;
	int number;
	bool current;
};

struct CIRCLE {
	POINT p;
	double r;
	string layer;
	int number;
	bool current;
};

struct ELLIPSE {
	POINT p;
	double ratio;
	double width;
	double height;
	double angle;	//���� �������� ������� ��� ������������ OX
	string layer;
	int number;
};

struct ARC {
	POINT p;
	double r;
	double angleStart;
	double angleEnd;
	string layer;
	int number;
	bool current;
};

struct BLOCK {
	int beginAddr;
	string number;
};

struct INSERT {
	string layer;
	int number;
	string blockNumber;
};

struct ENTITIES {
	vector<POINT> Points;
	vector<LINE> Lines;
	vector<CIRCLE> Circles;
	vector<ELLIPSE> Ellipses;
	vector<ARC> Arcs;
	vector<INSERT> Inserts;
};

struct SECTION {
	ENTITIES Entities;
};

struct CROSSPOINT {
	double x;
	double y;
	bool type;	//true - �������������� �����������, false - ������ �����������
	bool current;
	bool isCrossPoint;	//true - ����� �����������, false - ���������

	vector<LINE> Lines;
	vector<CIRCLE> Circles;
	vector<ELLIPSE> Ellipses;
	vector<ARC> Arcs;
};

class DXF {
public:
	/*struct POINT {
		double x;
		double y;
		unsigned short int type;	//0 - �������, 1 - �����������, 2 - ������ ����������
		string layer;
		int number;
	};

	struct LINE {
		POINT p[2];
		unsigned short int type;	//0 - LINE, 1 - XLINE
		string layer;
		int number;
	};

	struct CIRCLE {
		POINT p;
		double r;
		string layer;
		int number;
		bool current;
	};

	struct ELLIPSE {
		POINT p;
		double ratio;
		double width;
		double height;
		double angle;	//���� �������� ������� ��� ������������ OX
		string layer;
		int number;
	};

	struct ARC {
		POINT p;
		double r;
		double angleStart;
		double angleEnd;
		string layer;
		int number;
	};

	struct BLOCK {
		int beginAddr;
		string number;
	};

	struct INSERT {
		string layer;
		int number;
		string blockNumber;
	};

	struct ENTITIES {
		vector<POINT> Points;
		vector<LINE> Lines;
		vector<CIRCLE> Circles;
		vector<ELLIPSE> Ellipses;
		vector<ARC> Arcs;
		vector<INSERT> Inserts;
	};

	struct SECTION {
		ENTITIES Entities;
	};*/

private:
	fstream file;
	string fileName;
	ofstream saveFile;
	string saveFileName;
	
	int LastNumberOfObject;
	int EndEntitiesPointer;

	int TextToHex(string str);
	string LineToString(LINE l);
	string CircleToString(CIRCLE c);
	string ErrPointToString(CROSSPOINT point);
	string LayerToString(string name);
	void ReadLine();
	void ReadXLine();
	void ReadCircle();
	void ReadBlock();
	void ReadInsert();
	void ReadEllipse();
	void ReadArc();
	string PrintDxf();

public:
	SECTION _Section;	//������� private ��� protected

	int NumBlock;
	float errPointR;
	vector<BLOCK> Blocks;
	//vector<int> beginBlocksPointers;

	DXF();
	~DXF();
	bool Open(string dxfFileName);
	int Read();
	bool Save();
	bool SaveErrorPoints(vector<CROSSPOINT> errPoints);

};
#endif