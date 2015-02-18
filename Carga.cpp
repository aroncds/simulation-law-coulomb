#include "Carga.h"

Carga::Carga(double q, int exp) :Node(4)
{
	this->q = q;
	this->exp = exp;
	if (q > 0){
		_circle = new Circle(20, 15, 0, 0, 1);
		_line1 = new Line(-10, 0, 0, 10, 0, 0, 1);
		_line2 = new Line(0, -10, 0, 0, 10, 0, 1);
	}
	else{
		_circle = new Circle(20, 15, 1, 0, 0);
		_line1 = new Line(-10, 0, 0, 10, 0, 0, 1);
	}
	_arrow = new Arrow();
	addChild(_arrow);
	addChild(_circle);
	addChild(_line1);
	if (q > 0)
		addChild(_line2);
}

void Carga::Update(){
	if (q_angle != 0){
		_arrow->Rotation.v[2] = q_angle;
		float radians = (3.14f*q_angle) / 180;
		//std::cout << radians << std::endl;
	}
	else{
		_arrow->Rotation.v[2] += 0.3;
	}
	_arrow->visible = interactive;
	
	Node::Update();
}

float Carga::getRaio(){
	return _circle->getRaio();
}

void Carga::setPos(float x, float y){
	//float radians = (3.14f / 180) / q_angle;
	//_arrow->Position = vec3((cos(radians) * this->getRaio())*-4.4 + _circle->Position.v[0], (sin(radians) * this->getRaio())*-4.4 + _circle->Position.v[1], 0);
	_arrow->Position = vec3(x, y, 0);
	_circle->Position = vec3(x, y, 0);
	_line1->Position = vec3(x, y, 0);

	if (q > 0)
		_line2->Position = vec3(x, y, 0);
}

vec3 Carga::getPos(){
	return _circle->Position;
}

Carga::~Carga()
{
}
