#include "Arrow.h"

Arrow::Arrow()
{
	_points = 6;
	createArrow();
	createBasic();
	TypeRender = GL_LINES;
	Scale = vec3(5,5,1);
}


Arrow::~Arrow()
{
}

void Arrow::createArrow(){
	_obj = new GLfloat[18]{
		0.0f, 0.0f, 0.0f,
		20.0f, 0.0f, 0.0f,
		20.0f, 0.0f, 0.0f,
		16.0f, 1.5f, 0.0f,
		20.0f, 0.0f, 0.0f,
		16.0f, -1.5f, 0.0f
	};
	_color = new GLfloat[24]{
		0.0f, 0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f, 1.0f
	};
}