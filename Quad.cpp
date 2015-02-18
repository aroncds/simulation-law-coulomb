#include "Quad.h"


Quad::Quad(float width, float height, float r, float g, float b)
{
	_points = 4;
	createQuad(width,height,r,g,b);
	createBasic();
	TypeRender = GL_POLYGON;
}

void Quad::createQuad(float width, float height, float r, float g, float b){
	_obj = new float[12]{
		0.0f, 0.0f, 0.0f,
			width, 0.0f, 0.0f,
			width, height, 0.0f,
			0.0f, height, 0.0f
	};
	_color = new float[16]{
		r, g, b, 1.0f,
			r, g, b, 1.0f,
			r, g, b, 1.0f,
			r, g, b, 1.0f
	};
}

Quad::~Quad()
{
	Geometry::~Geometry();
}
