#include "stdafx.h"
#include "Cl_ObjectsLib.h"

WORK::WORK(SECTION s) {
	Section = s;
	//errPoints.clear();
	ErrPoints.clear();
}

double WORK::Det(double x1, double x2, double x3, double x4) {
	return (x1 * x4 - x2 * x3);
}

void WORK::CrossLines(LINE line1, LINE line2) {
	double x1 = line1.p[0].x;
	double y1 = line1.p[0].y;
	double x2 = line1.p[1].x;
	double y2 = line1.p[1].y;
	double x3 = line2.p[0].x;
	double y3 = line2.p[0].y;
	double x4 = line2.p[1].x;
	double y4 = line2.p[1].y;

	double a1 = y2 - y1;
	double b1 = x1 - x2;
	double a2 = y4 - y3;
	double b2 = x3 - x4;

	double c1 = x1 * a1 + y1 * b1;
	double c2 = x3 * a2 + y3 * b2;

	double det = Det(a1, b1, a2, b2);
	
	if(det != 0) {
		double detx, dety;
		detx = Det(c1, b1, c2, b2);
		dety = Det(a1, c1, a2, c2);
		double x, y;
		x = detx / det;
		y = dety / det;
		
		double u1 = ((x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3)) / det;
		double u2 = ((x2 - x1) * (y1 - y3) - (x1 - x3) * (y2 - y1)) / det;

		bool type;
		if((u1 >= 0 && u1 <= 1) && (u2 >= 0 && u2 <= 1)) type = true;
		else type = false;

		CROSSPOINT tmp1;
		if(type) tmp1.type = true;
		else tmp1.type = false;
		tmp1.current = false;
		tmp1.x = x;
		tmp1.y = y;
		tmp1.Lines.clear();
		tmp1.Circles.clear();
		tmp1.Ellipses.clear();
		tmp1.Arcs.clear();
		tmp1.Lines.push_back(line1);
		tmp1.Lines.push_back(line2);
		ErrPoints.push_back(tmp1);

	}
	else return;
}

void WORK::CrossCircles(CIRCLE circle1, CIRCLE circle2) {
	double x1 = circle1.p.x;
	double y1 = circle1.p.y;
	double r1 = circle1.r;
	double x2 = circle2.p.x;
	double y2 = circle2.p.y;
	double r2 = circle2.r;

	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if((r1 + r2 < d) || (abs(r1 - r2) > d)) return;

	double b = (d * d - r1 * r1 + r2 * r2) / (2 * d);
	double a = d - b;
	double h = sqrt(r1 * r1 - a * a);

	double x0 = x1 + a * (x2 - x1) / d;
	double y0 = y1 + a * (y2 - y1) / d;

	double tx1, ty1, tx2, ty2;
	tx1 = x0 + (y2 - y1) * h / d;
	ty1 = y0 - (x2 - x1) * h / d;
	
	CROSSPOINT tmp1;
	tmp1.type = true;
	tmp1.current = false;
	tmp1.x = tx1;
	tmp1.y = ty1;
	tmp1.Lines.clear();
	tmp1.Circles.clear();
	tmp1.Ellipses.clear();
	tmp1.Arcs.clear();
	tmp1.Circles.push_back(circle1);
	tmp1.Circles.push_back(circle2);
	ErrPoints.push_back(tmp1);

	tx2 = x0 - (y2 - y1) * h / d;
	ty2 = y0 + (x2 - x1) * h / d;

	if(tx1 == tx2 && ty1 == ty2) return;

	tmp1.type = true;
	tmp1.current = false;
	tmp1.x = tx2;
	tmp1.y = ty2;
	tmp1.Lines.clear();
	tmp1.Circles.clear();
	tmp1.Ellipses.clear();
	tmp1.Arcs.clear();
	tmp1.Circles.push_back(circle1);
	tmp1.Circles.push_back(circle2);
	ErrPoints.push_back(tmp1);
}

void WORK::CrossLineCircle(LINE line, CIRCLE circle) {
	double x1 = line.p[0].x;
	double y1 = line.p[0].y;
	double x2 = line.p[1].x;
	double y2 = line.p[1].y;
	double x0 = circle.p.x;
	double y0 = circle.p.y;
	double r = circle.r;

	if(x2 - x1 == 0) return;						//!!!!!!!!
	double a = (y2 - y1) / (x2 - x1);
	double b = y1 - x1 * a;
	double alpha = a * a + 1;
	double beta = 2 * (a * (b - y0) - x0);
	double gamma = x0 * x0 + pow(b - y0, 2) - r * r;

	long double q = beta * beta  - 4 * alpha * gamma;
	long double tx1 = (-beta + sqrt(beta * beta  - 4 * alpha * gamma)) / (2 * alpha);
	long double tx2 = (-beta - sqrt(beta * beta  - 4 * alpha * gamma)) / (2 * alpha);
	long double ty1 = a * tx1 + b;
	long double ty2 = a * tx2 + b;

	/*POINT tmp;
	tmp.type = 0;
	tmp.x = tx1;
	tmp.y = ty1;
	errPoints.insert(errPoints.end(), tmp);*/

	CROSSPOINT tmp1;
	tmp1.type = true;
	tmp1.current = false;
	tmp1.x = tx1;
	tmp1.y = ty1;
	tmp1.Lines.clear();
	tmp1.Circles.clear();
	tmp1.Ellipses.clear();
	tmp1.Arcs.clear();
	tmp1.Lines.push_back(line);
	tmp1.Circles.push_back(circle);
	ErrPoints.push_back(tmp1);

	if(tx1 == tx2 && ty1 == ty2) return;

	/*tmp.x = tx2;
	tmp.y = ty2;
	errPoints.insert(errPoints.end(), tmp);*/

	tmp1.type = true;
	tmp1.current = false;
	tmp1.x = tx2;
	tmp1.y = ty2;
	tmp1.Lines.clear();
	tmp1.Circles.clear();
	tmp1.Ellipses.clear();
	tmp1.Arcs.clear();
	tmp1.Lines.push_back(line);
	tmp1.Circles.push_back(circle);
	ErrPoints.push_back(tmp1);
}

void WORK::CrossLineEllipse(LINE line, ELLIPSE ellipse) {
	double x1 = line.p[0].x;
	double y1 = line.p[0].y;
	double x2 = line.p[1].x;
	double y2 = line.p[1].y;
	double x0 = ellipse.p.x;
	double y0 = ellipse.p.y;
	double a = ellipse.width;
	double b = ellipse.height;

	if(x2 - x1 == 0) return;						//!!!!!!!!
	double k = (y2 - y1) / (x2 - x1);
	double c = y1 - x1 * k;

	double alpha = k * k * a * a + b * b;
	double beta = 2 * (a * a * k * (c - y0) - b * b * x0);
	double gamma = b * b * x0 * x0 + a * a * (pow(c - y0, 2) - b * b);

	double determ = beta * beta - 4 * alpha * gamma;
	double tx1 = (-beta + sqrt(determ)) / 2 * alpha;
	double tx2 = (-beta - sqrt(determ)) / 2 * alpha;
	double ty1 = k * tx1 + c;
	double ty2 = k * tx2 + c;

	/*POINT tmp;
	tmp.type = 0;
	tmp.x = tx1;
	tmp.y = ty1;
	errPoints.insert(errPoints.end(), tmp);*/

	CROSSPOINT tmp1;
	tmp1.type = true;
	tmp1.current = false;
	tmp1.x = tx1;
	tmp1.y = ty1;
	tmp1.Lines.clear();
	tmp1.Circles.clear();
	tmp1.Ellipses.clear();
	tmp1.Arcs.clear();
	tmp1.Lines.push_back(line);
	tmp1.Ellipses.push_back(ellipse);
	ErrPoints.push_back(tmp1);

	if(tx1 == tx2 && ty1 == ty2) return;

	/*tmp.x = tx2;
	tmp.y = ty2;
	errPoints.insert(errPoints.end(), tmp);*/

	tmp1.type = true;
	tmp1.current = false;
	tmp1.x = tx2;
	tmp1.y = ty2;
	tmp1.Lines.clear();
	tmp1.Circles.clear();
	tmp1.Ellipses.clear();
	tmp1.Arcs.clear();
	tmp1.Lines.push_back(line);
	tmp1.Ellipses.push_back(ellipse);
	ErrPoints.push_back(tmp1);
}

void WORK::CrossLineArc(LINE line, ARC arc) {
	double x1 = line.p[0].x;
	double y1 = line.p[0].y;
	double x2 = line.p[1].x;
	double y2 = line.p[1].y;
	double x0 = arc.p.x;
	double y0 = arc.p.y;
	double r = arc.r;

	if(x2 - x1 == 0) return;						//!!!!!!!!
	double a = (y2 - y1) / (x2 - x1);
	double b = y1 - x1 * a;
	double alpha = a * a + 1;
	double beta = 2 * (a * (b - y0) - x0);
	double gamma = x0 * x0 + pow(b - y0, 2) - r * r;

	long double q = beta * beta  - 4 * alpha * gamma;
	long double tx1 = (-beta + sqrt(beta * beta  - 4 * alpha * gamma)) / (2 * alpha);
	long double tx2 = (-beta - sqrt(beta * beta  - 4 * alpha * gamma)) / (2 * alpha);
	long double ty1 = a * tx1 + b;
	long double ty2 = a * tx2 + b;


	double angle = GetAngle(x0, y0, tx1, ty1);
	if(angle >= arc.angleStart && angle <= arc.angleEnd){
		/*POINT tmp;
		tmp.type = 0;
		tmp.x = tx1;
		tmp.y = ty1;
		errPoints.insert(errPoints.end(), tmp);*/

		CROSSPOINT tmp1;
		tmp1.type = true;
		tmp1.current = false;
		tmp1.x = tx1;
		tmp1.y = ty1;
		tmp1.Lines.clear();
		tmp1.Circles.clear();
		tmp1.Ellipses.clear();
		tmp1.Arcs.clear();
		tmp1.Lines.push_back(line);
		tmp1.Arcs.push_back(arc);
		ErrPoints.push_back(tmp1);
	}

	if(tx1 == tx2 && ty1 == ty2) return;

	angle = GetAngle(x0, y0, tx2, ty2);
	if(angle >= arc.angleStart && angle <= arc.angleEnd){
		/*POINT tmp;
		tmp.type = 0;
		tmp.x = tx2;
		tmp.y = ty2;
		errPoints.insert(errPoints.end(), tmp);*/

		CROSSPOINT tmp1;
		tmp1.type = true;
		tmp1.current = false;
		tmp1.x = tx2;
		tmp1.y = ty2;
		tmp1.Lines.clear();
		tmp1.Circles.clear();
		tmp1.Ellipses.clear();
		tmp1.Arcs.clear();
		tmp1.Lines.push_back(line);
		tmp1.Arcs.push_back(arc);
		ErrPoints.push_back(tmp1);
	}
}

void WORK::CrossCircleArc(CIRCLE circle, ARC arc) {
	double x1 = circle.p.x;
	double y1 = circle.p.y;
	double r1 = circle.r;
	double x2 = arc.p.x;
	double y2 = arc.p.y;
	double r2 = arc.r;

	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if((r1 + r2 < d) || (abs(r1 - r2) > d)) return;

	double b = (d * d - r1 * r1 + r2 * r2) / (2 * d);
	double a = d - b;
	double h = sqrt(r1 * r1 - a * a);

	double x0 = x1 + a * (x2 - x1) / d;
	double y0 = y1 + a * (y2 - y1) / d;

	double tx1, ty1, tx2, ty2;
	tx1 = x0 + (y2 - y1) * h / d;
	ty1 = y0 - (x2 - x1) * h / d;

	tx2 = x0 - (y2 - y1) * h / d;
	ty2 = y0 + (x2 - x1) * h / d;


	double angle = GetAngle(x2, y2, tx1, ty1);
	if(angle >= arc.angleStart && angle <= arc.angleEnd){
		/*POINT tmp;
		tmp.type = 0;
		tmp.x = tx1;
		tmp.y = ty1;
		errPoints.insert(errPoints.end(), tmp);*/

		CROSSPOINT tmp1;
		tmp1.type = true;
		tmp1.current = false;
		tmp1.x = tx1;
		tmp1.y = ty1;
		tmp1.Lines.clear();
		tmp1.Circles.clear();
		tmp1.Ellipses.clear();
		tmp1.Arcs.clear();
		tmp1.Circles.push_back(circle);
		tmp1.Arcs.push_back(arc);
		ErrPoints.push_back(tmp1);
	}

	if(tx1 == tx2 && ty1 == ty2) return;

	angle = GetAngle(x2, y2, tx2, ty2);
	if(angle >= arc.angleStart && angle <= arc.angleEnd){
		/*POINT tmp;
		tmp.type = 0;
		tmp.x = tx2;
		tmp.y = ty2;
		errPoints.insert(errPoints.end(), tmp);*/

		CROSSPOINT tmp1;
		tmp1.type = true;
		tmp1.current = false;
		tmp1.x = tx2;
		tmp1.y = ty2;
		tmp1.Lines.clear();
		tmp1.Circles.clear();
		tmp1.Ellipses.clear();
		tmp1.Arcs.clear();
		tmp1.Circles.push_back(circle);
		tmp1.Arcs.push_back(arc);
		ErrPoints.push_back(tmp1);
	}
}

void WORK::CrossArcs(ARC arc1, ARC arc2) {
	double x1 = arc1.p.x;
	double y1 = arc1.p.y;
	double r1 = arc1.r;
	double x2 = arc2.p.x;
	double y2 = arc2.p.y;
	double r2 = arc2.r;

	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if((r1 + r2 < d) || (abs(r1 - r2) > d)) return;

	double b = (d * d - r1 * r1 + r2 * r2) / (2 * d);
	double a = d - b;
	double h = sqrt(r1 * r1 - a * a);

	double x0 = x1 + a * (x2 - x1) / d;
	double y0 = y1 + a * (y2 - y1) / d;

	double tx1, ty1, tx2, ty2;
	tx1 = x0 + (y2 - y1) * h / d;
	ty1 = y0 - (x2 - x1) * h / d;

	tx2 = x0 - (y2 - y1) * h / d;
	ty2 = y0 + (x2 - x1) * h / d;


	double angle1 = GetAngle(x1, y1, tx1, ty1);
	double angle2 = GetAngle(x2, y2, tx1, ty1);
	if(angle1 >= arc1.angleStart && angle1 <= arc1.angleEnd && angle2 >= arc2.angleStart && angle2 <= arc2.angleEnd){
		/*POINT tmp;
		tmp.type = 0;
		tmp.x = tx1;
		tmp.y = ty1;
		errPoints.insert(errPoints.end(), tmp);*/

		CROSSPOINT tmp1;
		tmp1.type = true;
		tmp1.current = false;
		tmp1.x = tx1;
		tmp1.y = ty1;
		tmp1.Lines.clear();
		tmp1.Circles.clear();
		tmp1.Ellipses.clear();
		tmp1.Arcs.clear();
		tmp1.Arcs.push_back(arc1);
		tmp1.Arcs.push_back(arc2);
		ErrPoints.push_back(tmp1);
	}

	angle1 = GetAngle(x1, y1, tx2, ty2);
	angle2 = GetAngle(x2, y2, tx2, ty2);
	if(angle1 >= arc1.angleStart && angle1 <= arc1.angleEnd && angle2 >= arc2.angleStart && angle2 <= arc2.angleEnd){
		/*POINT tmp;
		tmp.type = 0;
		tmp.x = tx2;
		tmp.y = ty2;
		errPoints.insert(errPoints.end(), tmp);*/

		CROSSPOINT tmp1;
		tmp1.type = true;
		tmp1.current = false;
		tmp1.x = tx2;
		tmp1.y = ty2;
		tmp1.Lines.clear();
		tmp1.Circles.clear();
		tmp1.Ellipses.clear();
		tmp1.Arcs.clear();
		tmp1.Arcs.push_back(arc1);
		tmp1.Arcs.push_back(arc2);
		ErrPoints.push_back(tmp1);
	}
}

bool WORK::OverlapLines(LINE l1, LINE l2) {
	if((l1.p[0].x == l2.p[0].x) && (l1.p[1].x == l2.p[1].x) && (l1.p[0].y == l2.p[0].y) && (l1.p[1].y == l2.p[1].y)) return true;
	double x1 = l1.p[0].x;
	double y1 = l1.p[0].y;
	double x2 = l1.p[1].x;
	double y2 = l1.p[1].y;
	double x3 = l2.p[0].x;
	double y3 = l2.p[0].y;
	double x4 = l2.p[1].x;
	double y4 = l2.p[1].y;
	if(x1 > x2 && y1 > y2) {
		double tmp = x2;
		x2 = x1;
		x1 = tmp;
		tmp = y2;
		y2 = y1;
		y1 = tmp;
	}
	if(x3 > x4 && y3 > y4) {
		double tmp = x4;
		x4 = x3;
		x3 = tmp;
		tmp = y4;
		y4 = y3;
		y3 = tmp;
	}

	if(x1 > x2 && y1 < y2) {
		double tmp = x2;
		x2 = x1;
		x1 = tmp;
		tmp = y2;
		y2 = y1;
		y1 = tmp;
	}
	if(x3 > x4 && y3 < y4) {
		double tmp = x4;
		x4 = x3;
		x3 = tmp;
		tmp = y4;
		y4 = y3;
		y3 = tmp;
	}

	if(abs(x1) > abs(x3) && abs(x2) < abs(x4) && abs(y1) > abs(y3) && abs(y2) < abs(y4)) {
		double tmp = x3; x3 = x1; x1 = tmp;
		tmp = x4; x4 = x2; x2 = tmp;
		tmp = y3; y3 = y1; y1 = tmp;
		tmp = y4; y4 = y2; y2 = tmp;
	}

	if(x2 - x1 == 0) return false;						//!!!!!!!!
	double a = (y2 - y1) / (x2 - x1);
	double b = y1 - x1 * a;
	if(x1 <= x3 && x2 >= x4 && y1 <= y3 && y2 >= y4 && ((float)y3 == (float)(a*x3 + b)) && ((float)y4 == (float)(a*x4 + b))) return true;
	if(x1 <= x3 && x2 >= x4 && y1 >= y3 && y2 <= y4 && ((float)y3 == (float)(a*x3 + b)) && ((float)y4 == (float)(a*x4 + b))) return true;

	return false;
}

bool WORK::OverlapCircles(CIRCLE c1, CIRCLE c2) {
	if((c1.p.x == c2.p.x) && (c1.p.y == c2.p.y) && (c1.r == c2.r)) return true;
	else return false;
}

bool WORK::OverlapEllipses(ELLIPSE e1, ELLIPSE e2) {
	if((e1.p.x == e2.p.x) && (e1.p.y == e2.p.y) && (e1.ratio == e1.ratio)) return true;
	else return false;
}

bool WORK::OverlapArcs(ARC a1, ARC a2) {
	if((a1.p.x == a2.p.x) && (a1.p.y == a2.p.y) && (a1.r == a2.r) && (a1.angleStart == a2.angleStart) && (a1.angleEnd == a2.angleEnd)) return true;
	else return false;
}

bool WORK::OverlapCircleArc(CIRCLE c, ARC a) {
	if((c.p.x == a.p.x) && (c.p.y == a.p.y) && (c.r == a.r)) return true;
	else return false;
}

void WORK::CheckCross(BITSFIELD bitsfield) {
	ErrPoints.clear();
	//errPoints.clear();
	unsigned int i, j;

	if(bitsfield.line_line) for(i=0; i<Section.Entities.Lines.size(); i++) {
		for(j=i+1; j<Section.Entities.Lines.size(); j++) {
			CrossLines(Section.Entities.Lines[i], Section.Entities.Lines[j]);
		}
	}

	if(bitsfield.line_circle) for(i=0; i<Section.Entities.Lines.size(); i++) {
		for(j=0; j<Section.Entities.Circles.size(); j++) {
			CrossLineCircle(Section.Entities.Lines[i], Section.Entities.Circles[j]);
		}
	}

	if(bitsfield.line_ellipse) for(i=0; i<Section.Entities.Lines.size(); i++) {
		for(j=0; j<Section.Entities.Ellipses.size(); j++) {
			CrossLineEllipse(Section.Entities.Lines[i], Section.Entities.Ellipses[j]);
		}
	}

	if(bitsfield.circle_circle) for(i=0; i<Section.Entities.Circles.size(); i++) {
		for(j=i+1; j<Section.Entities.Circles.size(); j++) {
			CrossCircles(Section.Entities.Circles[i], Section.Entities.Circles[j]);
		}
	}

	if(bitsfield.overlap_lines) for(i=0; i<Section.Entities.Lines.size(); i++) {
		for(j=i+1; j<Section.Entities.Lines.size(); j++) {
			bool rez = OverlapLines(Section.Entities.Lines[i], Section.Entities.Lines[j]);
		}
	}

	if(bitsfield.overlap_circles) for(i=0; i<Section.Entities.Circles.size(); i++) {
		for(j=i+1; j<Section.Entities.Circles.size(); j++) {
			bool rez = OverlapCircles(Section.Entities.Circles[i], Section.Entities.Circles[j]);
		}
	}

	if(bitsfield.overlap_ellipses) for(i=0; i<Section.Entities.Ellipses.size(); i++) {
		for(j=i+1; j<Section.Entities.Ellipses.size(); j++) {
			bool rez = OverlapEllipses(Section.Entities.Ellipses[i], Section.Entities.Ellipses[j]);
		}
	}

	if(bitsfield.overlap_arcs) for(i=0; i<Section.Entities.Arcs.size(); i++) {
		for(j=i+1; j<Section.Entities.Arcs.size(); j++) {
			bool rez = OverlapArcs(Section.Entities.Arcs[i], Section.Entities.Arcs[j]);
		}
	}

	if(bitsfield.overlap_circle_arc) for(i=0; i<Section.Entities.Circles.size(); i++) {
		for(j=0; j<Section.Entities.Arcs.size(); j++) {
			bool rez = OverlapCircleArc(Section.Entities.Circles[i], Section.Entities.Arcs[j]);
		}
	}

	if(bitsfield.line_arc) for(i=0; i<Section.Entities.Lines.size(); i++) {
		for(j=0; j<Section.Entities.Arcs.size(); j++) {
			CrossLineArc(Section.Entities.Lines[i], Section.Entities.Arcs[j]);
		}
	}

	if(bitsfield.circle_arc) for(i=0; i<Section.Entities.Circles.size(); i++) {
		for(j=0; j<Section.Entities.Arcs.size(); j++) {
			CrossCircleArc(Section.Entities.Circles[i], Section.Entities.Arcs[j]);
		}
	}

	if(bitsfield.arc_arc) for(i=0; i<Section.Entities.Arcs.size(); i++) {
		for(j=i+1; j<Section.Entities.Arcs.size(); j++) {
			CrossArcs(Section.Entities.Arcs[i], Section.Entities.Arcs[j]);
		}
	}
}

void WORK::InitBitsField(BITSFIELD &field) {
	field.crossKind = 0;
	field.line_line = false;
	field.line_circle = false;
	field.line_ellipse = false;
	field.line_arc = false;
	field.circle_circle = false;
	field.circle_ellipse = false;
	field.circle_arc = false;
	field.ellipse_ellipse = false;
	field.ellipse_arc = false;
	field.arc_arc = false;
	field.overlap_lines = false;
	field.overlap_circles = false;
	field.overlap_ellipses = false;
	field.overlap_arcs = false;
	field.overlap_circle_arc = false;
}

double WORK::GetAngle(double x0, double y0, double x1, double y1) {
	double a = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
	double angle = acos(abs(x1 - x0) / a) * (180 / PI);
	double dx = abs(x1) - abs(x0);
	double dy = abs(y1) - abs(y0);
	if(dx < 0 && dy >= 0) angle = 180 - angle;
	if(dx < 0 && dy < 0) angle += 180;
	if(dx >= 0 && dy < 0) angle = 360 - angle;
	return angle;
}

bool WORK::IsCirclesCross(CIRCLE c1, CIRCLE c2) {
	double d = sqrt(pow(c2.p.x - c1.p.x, 2) + pow(c2.p.y - c1.p.y, 2));
	if((c1.r + c2.r < d) || (abs(c1.r - c2.r) > d)) return false;
	return true;
}

void WORK::ClickOnObject(double x, double y, double scale, DataGridView^ table) {
	unsigned int i;
	int numRow = 0;
	//Убрать метки
	for(i=0; i<Section.Entities.Circles.size(); i++){
		if(Section.Entities.Circles[i].current) Section.Entities.Circles[i].current = false;
	}
	for(i=0; i<ErrPoints.size(); i++){
		if(ErrPoints[i].current) ErrPoints[i].current = false;
	}
	table->Rows->Clear();

	CIRCLE tmp;
	tmp.p.x = x;
	tmp.p.y = y;
	tmp.r = 4 / scale;
	for(i=0; i<Section.Entities.Circles.size(); i++){
		if(IsCirclesCross(Section.Entities.Circles[i], tmp)) {
			if(Section.Entities.Circles[i].current) return;

			Section.Entities.Circles[i].current = true;
			table->Rows->Add();
			table->Rows[0]->Cells[0]->Value = "Тип";
			table->Rows[0]->Cells[1]->Value = "CIRCLE";
			table->Rows->Add();
			table->Rows[1]->Cells[0]->Value = "X";
			table->Rows[1]->Cells[1]->Value = "" + Section.Entities.Circles[i].p.x;
			table->Rows->Add();
			table->Rows[2]->Cells[0]->Value = "Y";
			table->Rows[2]->Cells[1]->Value = "" + Section.Entities.Circles[i].p.y;
			table->Rows->Add();
			table->Rows[3]->Cells[0]->Value = "Радиус";
			table->Rows[3]->Cells[1]->Value = "" + Section.Entities.Circles[i].r;
			table->Rows->Add();
			table->Rows[4]->Cells[0]->Value = "Слой";
			table->Rows[4]->Cells[1]->Value = gcnew System::String(Section.Entities.Circles[i].layer.c_str());

			return;
		}
	}

	CIRCLE err;
	err.r = errPointR;

	for(i=0; i<ErrPoints.size(); i++) {
		numRow = 0;
		err.p.x = ErrPoints[i].x;
		err.p.y = ErrPoints[i].y;
		if(IsCirclesCross(err, tmp)) {
			if(ErrPoints[i].current) return;

			ErrPoints[i].current = true;
			table->Rows->Add();
			table->Rows[numRow]->Cells[0]->Value = "Тип";
			table->Rows[numRow++]->Cells[1]->Value = "ErrPoint";
			table->Rows->Add();
			table->Rows[numRow]->Cells[0]->Value = "X";
			table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].x;
			table->Rows->Add();
			table->Rows[numRow]->Cells[0]->Value = "Y";
			table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].y;
			table->Rows->Add();
			table->Rows[numRow]->Cells[0]->Value = "Радиус";
			table->Rows[numRow++]->Cells[1]->Value = "" + errPointR;
			table->Rows->Add();
			numRow++;

			if(!ErrPoints[i].Lines.empty()) {
				unsigned int j;
				for(j=0; j<ErrPoints[i].Lines.size(); j++) {
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Тип";
					table->Rows[numRow++]->Cells[1]->Value = "LINE";
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "X[1]";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Lines[j].p[0].x;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Y[1]";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Lines[j].p[0].y;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "X[2]";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Lines[j].p[1].x;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Y[2]";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Lines[j].p[1].y;
				}
			}

			if(!ErrPoints[i].Circles.empty()) {
				unsigned int j;
				for(j=0; j<ErrPoints[i].Circles.size(); j++) {
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Тип";
					table->Rows[numRow++]->Cells[1]->Value = "CIRCLE";
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "X";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Circles[j].p.x;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Y";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Circles[j].p.y;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Радиус";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Circles[j].r;
				}
			}

			if(!ErrPoints[i].Ellipses.empty()) {
				unsigned int j;
				for(j=0; j<ErrPoints[i].Ellipses.size(); j++) {
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Тип";
					table->Rows[numRow++]->Cells[1]->Value = "ELLIPSE";
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "X";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Ellipses[j].p.x;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Y";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Ellipses[j].p.y;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Угол наклона наибольшей оси";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Ellipses[j].angle;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Отношение наибольшей к наименьшей оси";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Ellipses[j].ratio;
				}
			}

			if(!ErrPoints[i].Arcs.empty()) {
				unsigned int j;
				for(j=0; j<ErrPoints[i].Arcs.size(); j++) {
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Тип";
					table->Rows[numRow++]->Cells[1]->Value = "ELLIPSE";
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "X";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Arcs[j].p.x;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Y";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Arcs[j].p.y;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Радиус";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Arcs[j].r;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Начальный угол";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Arcs[j].angleStart;
					table->Rows->Add();
					table->Rows[numRow]->Cells[0]->Value = "Конечный угол";
					table->Rows[numRow++]->Cells[1]->Value = "" + ErrPoints[i].Arcs[j].angleEnd;
				}
			}

			return;
		}
		
	}

	//Убрать метки
	for(i=0; i<Section.Entities.Circles.size(); i++){
		if(Section.Entities.Circles[i].current) Section.Entities.Circles[i].current = false;
	}
	for(i=0; i<ErrPoints.size(); i++){
		if(ErrPoints[i].current) ErrPoints[i].current = false;
	}
	table->Rows->Clear();
}
