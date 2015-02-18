#ifndef _LINE_H_
#define _LINE_H_

#pragma once
#include "Geometry.h"

class Line :
	public Geometry
{
private:
	
public:
	Line(float x, float y, float z, float x2, float y2, float z2, float color);
	void CreateLine(float x, float y, float z, float x2, float y2, float z2, float color);
	void UpdateBuffer();
	~Line();
};

#endif

