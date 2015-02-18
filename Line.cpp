#include "Line.h"

Line::Line(float x, float y, float z, float x2, float y2, float z2, float color)
{
	_points = 2;
	CreateLine(x,y,z,x2,y2,z2,color);
	createBasic();
	TypeRender = GL_LINES;
}

void Line::CreateLine(float x, float y, float z, float x2, float y2, float z2, float color){
	_obj = new GLfloat[6]{
		x, y, z,
		x2, y2, z2
	};
	_color = new GLfloat[8]{
		color, color, color, 1.0f,
		color, color, color, 1.0f
	};
}

void Line::UpdateBuffer(){
	glBindBuffer(GL_ARRAY_BUFFER, _bufferObj);
	glBufferData(GL_ARRAY_BUFFER, (_points * 3) * sizeof(GLfloat), _obj, GL_STATIC_DRAW);
}

Line::~Line()
{
}
