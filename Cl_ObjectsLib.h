#ifndef CL_OBJECTSLIB_H
#define CL_OBJECTSLIB_H

#include "Cl_DxfLib.h"
#include "Cl_GraphicsLib.h"

using namespace System;
using namespace System::Windows::Forms;

class WORK: public DXF {
private:
	double Det(double x1, double x2, double x3, double x4);
	void CrossLines(LINE line1, LINE line2, unsigned char crossKind);
	void CrossLineCircle(LINE line, CIRCLE circle, unsigned char crossKind);
	void CrossLineEllipse(LINE l, ELLIPSE e);
	void CrossLineArc(LINE line, ARC arc, unsigned char crossKind);
	void CrossCircles(CIRCLE circle1, CIRCLE circle2);
	void CrossCircleArc(CIRCLE c, ARC a);
	void CrossArcs(ARC a1, ARC a2);

	bool OverlapLines(LINE l1, LINE l2);
	bool OverlapCircles(CIRCLE c1, CIRCLE c2);
	bool OverlapEllipses(ELLIPSE e1, ELLIPSE e2);
	bool OverlapArcs(ARC a1, ARC a2);

	bool OverlapCircleArc(CIRCLE c, ARC a);

	double GetAngle(double x0, double y0, double x1, double y1);	//��������� ���� ����� ���� OX � ������, ���������� ����� ����� X � Y
public:
	struct BITSFIELD {
		unsigned char crossKind;	//0 - ��� �����������, 1 - ������ ��������������, 2 - ������ ������

		bool line_line;
		bool line_circle;
		bool line_ellipse;
		bool line_arc;
		bool circle_circle;
		bool circle_ellipse;
		bool circle_arc;
		bool ellipse_ellipse;
		bool ellipse_arc;
		bool arc_arc;
		
		bool overlap_lines;
		bool overlap_circles;
		bool overlap_ellipses;
		bool overlap_arcs;

		bool overlap_circle_arc;
	};

	SECTION Section;
	vector<CROSSPOINT> ErrPoints;

	WORK(SECTION s);
	void CheckCross(BITSFIELD bitsfield);
	void InitBitsField(BITSFIELD &field);

	bool IsPointOnLine(LINE line, double x, double y);

	bool IsLineCircleCross(LINE line, CIRCLE circle);
	bool IsCirclesCross(CIRCLE c1, CIRCLE c2);
	void ClickOnObject(double x, double y, double scale, DataGridView^ table);
};
#endif