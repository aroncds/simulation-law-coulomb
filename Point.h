#pragma once
#include "Geometry.h"
class Point :
	public Geometry
{
private:
	GLint _length = 0;
	GLint _add = 0;
public:
	void addPoint(float x, float y, float z);
	void addColor(float r, float g, float b);
	void drawFullScreen();
	void quantPoint(int length);
	Point(bool full);
	~Point();
};

