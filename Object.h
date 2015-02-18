/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Classe fundamental para todos os objetos que serão renderizados em um contexto 2D

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "GL\glew.h"
#include "GL\glut.h"
#include "maths_funcs.h"
#include "ManagerAsset.h"
#include <iostream>

class Object{

private:
	
public:
	vec3 Position = vec3(0,0,0);
	vec3 Scale = vec3(1,1,1);
	vec3 Rotation = vec3(0, 0, 0);
	bool visible = true;
	virtual void Update();
	virtual void Render(float* camera);
	virtual void Render(float* camera, mat4 parent);
	bool pressed = false;
};

#endif