/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Classe voltada para gerar um grafico de acordo com os dados informados

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#pragma once
#include "Node.h"
#include "Line.h"
#include "Point.h"
#include "Circle.h"
#include "EletricField.h"
#include "Quad.h"

class Graphic : public Node
{
private:
	Line ** _lines;
	double * points;
	double * dist;
	double * force;
	int quantData = 0;
	Point * p;
	int forceMax=0, forceMin=0, distMax=0, distMin=0;
	Circle * current;
	bool generate = false;
	int width = 0;
	int height = 0;
public:
	void generateGraphic();
	Graphic(int width, int height);
	void addData(double dist, double force);
	virtual void Update() override;
	static Graphic * Instance;
	static void Init(int width, int height);
	~Graphic();
};

#endif
