#pragma once
#include "Geometry.h"
class Quad :
	public Geometry
{
private:
	void createQuad(float width, float height, float r, float g, float b);
public:
	Quad(float width, float height, float r,float g, float b);
	~Quad();
};

