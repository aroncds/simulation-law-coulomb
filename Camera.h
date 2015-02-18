/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Manipulação de camera 2D;

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#include "maths_funcs.h"
#include "GL\glut.h"
#pragma once

class Camera
{
private:
	mat4 _matrix;
	GLfloat * _projection;

public:
	void Update();

	vec3 Position = vec3(0, 0, 0);
	vec3 Scale = vec3(1, 1, 1);
	vec3 Rotation = vec3(0, 0, 0);

	void setOrtographic(float l, float r, float t, float b, float n, float f);
	void setProjection();
	float* getMatrix();

	Camera();
	virtual ~Camera();
};

