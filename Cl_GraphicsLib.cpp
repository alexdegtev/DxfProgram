#include "stdafx.h"
#include "Cl_GraphicsLib.h"
using namespace GRAPHICS_SPACE;

GRAPHICS::GRAPHICS() {
	IsInit = false;
}

GRAPHICS::~GRAPHICS() {
	OpenGlControl->DestroyContexts();
	delete OpenGlControl;
}

void GRAPHICS::GetOpenGlControl(SimpleOpenGlControl^  simpleOpenGlControl) {
	OpenGlControl = simpleOpenGlControl;
	IsInit = true;
}

int GRAPHICS::InitGL() {
	if(!IsInit) return -1;
	OpenGlControl->InitializeContexts();

	Glut::glutInit();
	Glut::glutInitDisplayMode(Glut::GLUT_RGB | Glut::GLUT_DOUBLE); 
	Gl::glClearColor(255, 255, 255, 1);

	Resize((double)OpenGlControl->Width, (double)OpenGlControl->Height);

	return 0;
}

/*void GRAPHICS::Resize(int width, int height) {
	if(height == 0) height = 1;

	Gl::glViewport(0, 0, width, height);

	Gl::glMatrixMode(Gl::GL_PROJECTION);
	Gl::glLoadIdentity();

	double nRange = 100.0;
	if(width<=height) Gl::glOrtho(-nRange, nRange, -nRange*height/width, nRange*height/width, -nRange, nRange);
	else Gl::glOrtho(-nRange*width/height, nRange*width/height, -nRange, nRange, -nRange, nRange);

	Gl::glMatrixMode(Gl::GL_MODELVIEW);
	Gl::glLoadIdentity();
}*/

void GRAPHICS::Resize(double width, double height) {
	if(height == 0.0) height = 1.0;

	Gl::glViewport(0, 0, width, height);

	Gl::glMatrixMode(Gl::GL_PROJECTION);
	Gl::glLoadIdentity();

	Gl::glOrtho(-width/2.0, width/2.0, -height/2.0, height/2.0, -1, 1);

	Gl::glMatrixMode(Gl::GL_MODELVIEW);
	Gl::glLoadIdentity();
}

void GRAPHICS::Render() {
	Gl::glClear(Gl::GL_COLOR_BUFFER_BIT);
	Gl::glColor3f(0.0f, 0.0f, 0.0f);
			
	Gl::glColor3f(0.8f, 0.8f, 0.8f);

	Gl::glBegin(Gl::GL_LINE_STRIP);    // OX --
		Gl::glVertex2f(0,0);
		Gl::glVertex2f(100,0);
	Gl::glEnd();
	Gl::glBegin(Gl::GL_LINE_STRIP);    // OX ->
		Gl::glVertex2f(90,3);
		Gl::glVertex2f(100,0);
		Gl::glVertex2f(90,-3);
	Gl::glEnd();
	/*Gl::glBegin(Gl::GL_LINES);    // X
		Gl::glVertex2f(107,5);
		Gl::glVertex2f(113,-5);
		Gl::glVertex2f(107,-5);
		Gl::glVertex2f(113,5);
	Gl::glEnd();*/

	Gl::glBegin(Gl::GL_LINE_STRIP);    // OY --
		Gl::glVertex2f(0,0);
		Gl::glVertex2f(0,100);
	Gl::glEnd();
	Gl::glBegin(Gl::GL_LINE_STRIP);    // OY ->
		Gl::glVertex2f(-3,90);
		Gl::glVertex2f(0,100);
		Gl::glVertex2f(3,90);
	Gl::glEnd();
	/*Gl::glBegin(Gl::GL_LINES);    // Y
		Gl::glVertex2f(-3,113);
		Gl::glVertex2f(0,110);
		Gl::glVertex2f(0,110);
		Gl::glVertex2f(3,113);
		Gl::glVertex2f(0,110);
		Gl::glVertex2f(0,107);
	Gl::glEnd();*/

	Gl::glColor3f(0.0f, 0.0f, 0.0f);
}

void GRAPHICS::SwapBuffers() {
	Gl::glFlush();
	OpenGlControl->Invalidate();
}

void GRAPHICS::Scale(signed short int s) {
	if(s == 1) Gl::glScaled(2.0, 2.0, 1.0);
	if(s == -1) Gl::glScaled(0.5, 0.5, 1.0);
}

void GRAPHICS::Translate(double x, double y) {
	Gl::glTranslated(x, y, 0);
}

void GRAPHICS::DrawPoint(double x, double y, float size) {
	Gl::glPointSize(size);
	Gl::glBegin(Gl::GL_POINTS);
		Gl::glVertex2d(x, y);
	Gl::glEnd();
	Gl::glPointSize(1.0);
}

void GRAPHICS::DrawLine(double x1, double y1, double x2, double y2) {
	Gl::glBegin(Gl::GL_LINES);
		Gl::glVertex2d(x1, y1);
		Gl::glVertex2d(x2, y2);
	Gl::glEnd();
}

void GRAPHICS::DrawCircle(double x, double y, double r) {
	int segments = 300;
	Gl::glBegin(Gl::GL_LINE_LOOP);
		for(int i=0; i < segments; i++) {
			double alpha = 2 * PI * i / segments;
			double dx = r * cos(alpha);
			double dy = r * sin(alpha);
			Gl::glVertex2d(x + dx, y + dy);
		}
	Gl::glEnd();
}

void GRAPHICS::DrawErrorPoint(double x, double y, double r) {
	Gl::glColor3f(1.0f, 0.0f, 0.0f);
	DrawCircle(x, y, r);
	Gl::glColor3f(0.0f, 0.0f, 0.0f);
}

void GRAPHICS::DrawArc(double x, double y, double r, double begin, double end) {
	int segments = 300;
	if(begin > end) end += 360.0;
	double beta;
	Gl::glBegin(Gl::GL_LINE_STRIP);
		for(int alpha=begin; alpha<end; alpha++) {
			beta = alpha * PI / 180;
			double dx = r * cos(beta);
			double dy = r * sin(beta);
			Gl::glVertex2d(x + dx, y + dy);
		}
	Gl::glEnd();
}

/*good*/
void GRAPHICS::DrawEllipse(double x, double y, double a, double b, double angle) {
	int segments = 300;
	Gl::glPushMatrix();
		Gl::glTranslated(x, y, 0);
		Gl::glRotated(angle, 0, 0, 1);
		Gl::glBegin(Gl::GL_LINE_LOOP);
			for(int i=0; i < segments; i++) {
				double alpha = 2 * PI * i / segments;
				double dx = a * cos(alpha);
				double dy = b * sin(alpha);
				Gl::glVertex2d(dx, dy);
			}
		Gl::glEnd();
	Gl::glPopMatrix();
}

/*
void GRAPHICS::DrawEllipse(double x, double y, double a, double b, double angle) {
	int segments = 300;
	Gl::glPushMatrix();
		Gl::glTranslated(x, y, 0);
		Gl::glRotated(angle, 0, 0, 1);
		Gl::glBegin(Gl::GL_LINE_LOOP);
			for(int i=0; i < segments; i++) {
				double alpha = 2 * PI * i / segments;
				double dx = a * cos(alpha);
				double dy = b * sin(alpha);
				Gl::glVertex2d(dx, dy);
			}
		Gl::glEnd();
	Gl::glPopMatrix();

	double phy = 90 - angle;
	double cosPhy = cos(phy);
	double sinPhy = sin(phy);
	double b_a = b / a;

	Gl::glPushMatrix();
		//Gl::glTranslated(x, y, 0);
		//Gl::glRotated(angle, 0, 0, 1);
		Gl::glBegin(Gl::GL_LINE_LOOP);
			for(int i=0; i < segments; i++) {
				
				Gl::glVertex2d(dx, dy);
			}
		Gl::glEnd();
	Gl::glPopMatrix();
}
*/

/*void GRAPHICS::PrintCursor(int x, int y) {
	Gl::glColor3f(1.0f, 0.0f, 0.0f);
	Gl::glPointSize(20.0);
	Gl::glBegin(Gl::GL_POINTS);
		Gl::glVertex2i(x, y);
	Gl::glEnd();
	Gl::glPointSize(1.0);
	Gl::glColor3f(0.0f, 0.0f, 0.0f);
}*/

void GRAPHICS::SetColor(float red, float green, float blue) { Gl::glColor3f(red, green, blue); }
