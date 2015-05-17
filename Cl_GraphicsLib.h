#ifndef CL_GRAPHICS_H
#define CL_GRAPHICS_H

#include "Cl_DxfLib.h"

namespace GRAPHICS_SPACE {

	using namespace System::Windows::Forms;
	// для работы с библиотекой OpenGL 
	using namespace Tao::OpenGl;
	// для работы с библиотекой FreeGLUT 
	using namespace Tao::FreeGlut;
	// для работы с элементом управления SimpleOpenGLControl 
	using namespace Tao::Platform::Windows;

	ref class GRAPHICS {
	private:
		SimpleOpenGlControl^  OpenGlControl;
		bool IsInit;

	public:
		GRAPHICS();
		~GRAPHICS();
		void GetOpenGlControl(SimpleOpenGlControl^  simpleOpenGlControl);
		int InitGL();
		void Resize(int width, int height);
		void Resize(double width, double height);
		void Render();
		void SwapBuffers();
		void Scale(signed short int s);
		void Translate(double x, double y);
		void DrawPoint(double x, double y, float size);
		void DrawLine(double x1, double y1, double x2, double y2);
		void DrawCircle(double x, double y, double r);
		void DrawErrorPoint(double x, double y, double r);
		void DrawArc(double x, double y, double r, double begin, double end);
		void DrawEllipse(double x, double y, double a, double b, double angle);
		void PrintCursor(int x, int y);
		void SetColor(float red, float green, float blue);
		bool GetIsInit() { return IsInit; }
	};
}
#endif