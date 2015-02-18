#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#pragma once
#include "Geometry.h"

class Circle :
	public Geometry
{
public:
	Circle(float raio, int points, float r, float g, float b);
	virtual ~Circle();
	float getRaio();

private:
	void CreateCircle(float raio, float points, float r, float g, float b);
	float raio = 0;
};

#endif
