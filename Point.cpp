#include "Point.h"

Point::Point(bool full)
{
	if (full){
		drawFullScreen();
	}
	TypeRender = GL_POINTS;
}

void Point::addPoint(float x, float y, float z){
		_obj[_add] = x;
		_obj[_add + 1] = y;
		_obj[_add + 2] = z;

		_add += 3;
}

void Point::addColor(float r, float b, float g){
	for (int i = 0; i < _points * 4; i += 4){
		_color[i] = r;
		_color[i + 1] = g;
		_color[i + 2] = b;
		_color[i + 3] = 1.0f;
	}
}

void Point::quantPoint(int length){
	_points = length;
	_obj = (GLfloat*)calloc(_points * 3, sizeof(GLfloat));
	_color = (GLfloat*)calloc(_points * 4, sizeof(GLfloat));
}

void Point::drawFullScreen(){
	float x = 0;
	float y = 7;

	quantPoint(160 * 120);
	for (int i = 0; i < _points; i++){
		if (x == 800){
			x = 0;
			y += 5;
		}
		else x += 5;

		addPoint(x, y, 0);
	}
	addColor(0, 0, 0);
	createBasic();
}


Point::~Point()
{
	Geometry::~Geometry();
}
