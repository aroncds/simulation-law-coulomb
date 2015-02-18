#include "Circle.h"
#include <math.h>

Circle::Circle(float raio, int points, float r,float g, float b)
{
	this->_points = (2 * points) + int((2*points)/3);
	this->CreateCircle(raio, points, r, g, b);
	this->createBasic();
	this->TypeRender = GL_TRIANGLE_FAN;
	this->raio = raio;
}

float Circle::getRaio(){
	return this->raio;
}

void Circle::CreateCircle(float raio, float points, float r, float g, float b){
	
	int a = 0;
	int p = 0; 
	_obj = (GLfloat *)calloc(_points*3, sizeof(GLfloat));
	_color = (GLfloat *)calloc(_points*4, sizeof(GLfloat));

	for (float i = 0; i < 2 * 3.14f; i += 3.14f / points){
		_obj[a] = cos(i) * raio;
		_obj[a + 1] = sin(i) * raio;
		_obj[a + 2] = 0;
		 a += 3;
	}

	for (int i = 0; i < _points * 4; i += 4){
		_color[i] = r;
		_color[i + 1] = g;
		_color[i + 2] = b;
		_color[i + 3] = 1.0f;
	}
}

Circle::~Circle(){

}
