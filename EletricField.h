/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Classe para manipular as cargas, criação de cargas, calculo de força e movimento

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#ifndef _ELETRICFIELD_H_
#define _ELETRICFIELD_H_

#pragma once
#include "Carga.h"
#include <string>
#include <sstream>
#include "Graphic.h"

#define K					9E9

class EletricField : public Node
{
private:
	Carga ** _q;
	int MAX=0;
	
	float getRadianCargas(vec3 q, vec3 q2);
	float DistanceCargas(vec3 q, vec3 q2);
	void Force(Carga*q, Carga*q2);
	void Field(Carga*q);
	bool alter = false;
public:
	void Update();
	void CreateCarga(double q, int exp);
	static void Init(int max);
	void onSelectedCarga(float mouseX, float mouseY);
	EletricField(int max);
	void EletricField::ForceByDistance(Carga*q, Carga*q2, float distance);
	static EletricField * Instance;
	static double Force_2;
	static double Dist_2;int length=0;
};
#endif

