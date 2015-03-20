#ifndef CL_OBJECTSLIB_H
#define CL_OBJECTSLIB_H

#include "Cl_DxfLib.h"
#include "Cl_GraphicsLib.h"

using namespace System;
using namespace System::Windows::Forms;


class WORK: public DXF {
private:
	double Det(double x1, double x2, double x3, double x4);
	void CrossLines(LINE l1, LINE l2);
	void CrossLineCircle(LINE l, CIRCLE c);
	void CrossLineEllipse(LINE l, ELLIPSE e);
	void CrossLineArc(LINE l, ARC a);
	void CrossCircles(CIRCLE c1, CIRCLE c2);
	void CrossCircleArc(CIRCLE c, ARC a);
	void CrossArcs(ARC a1, ARC a2);

	bool OverlapLines(LINE l1, LINE l2);
	bool OverlapCircles(CIRCLE c1, CIRCLE c2);
	bool OverlapEllipses(ELLIPSE e1, ELLIPSE e2);
	bool OverlapArcs(ARC a1, ARC a2);

	bool OverlapCircleArc(CIRCLE c, ARC a);

	double GetAngle(double x0, double y0, double x1, double y1);
public:
	struct BITSFIELD {
		unsigned int line_line:1;
		unsigned int line_circle:1;
		unsigned int line_ellipse:1;
		unsigned int line_arc:1;
		unsigned int circle_circle:1;
		unsigned int circle_ellipse:1;
		unsigned int circle_arc:1;
		unsigned int ellipse_ellipse:1;
		unsigned int ellipse_arc:1;
		unsigned int arc_arc:1;
		
		unsigned int overlap_lines:1;
		unsigned int overlap_circles:1;
		unsigned int overlap_ellipses:1;
		unsigned int overlap_arcs:1;

		unsigned int overlap_circle_arc:1;
	};

	SECTION Section;
	vector<POINT> errPoints;

	//WORK();
	WORK(SECTION s);
	void CheckCross(BITSFIELD bitsfield);
	void InitBitsField(BITSFIELD &field);

	bool IsCirclesCross(CIRCLE c1, CIRCLE c2);
	void ClickOnObject(double x, double y, double scale, DataGridView^ table);
};
#endif