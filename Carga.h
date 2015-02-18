/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Classe referente as cargas, que serão inseridas no contexto

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#pragma once
#include "Node.h"
#include "Circle.h"
#include "Arrow.h"
#include "Line.h"

class Carga :
	public Node
{
private:
	Circle *_circle;
	Object *_arrow;
	Line *_line1;
	Line * _line2;
public:
	float getRaio();
	double q;
	bool interactive = false;
	int exp;
	float q_angle;
	virtual void Update() override;
	void setPos(float x, float y);
	vec3 getPos();
	Carga(double q, int exp);
	~Carga();
};

