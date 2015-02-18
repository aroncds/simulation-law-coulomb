#include "EletricField.h"

EletricField * EletricField::Instance;
double EletricField::Force_2;
double EletricField::Dist_2;

EletricField::EletricField(int max):Node(2){
	MAX = max;
	_q = (Carga**)calloc(MAX, sizeof(Carga));

}

void EletricField::Update(){
	if (length==2){
		vec3 pos = _q[0]->getPos();
		vec3 pos2 = _q[1]->getPos();

		float angle = 0;
		float angle2 = 0;

		angle = (_q[0]->q > 0 ? (180.0f / 3.14f) * getRadianCargas(pos2, pos) : (180.0f / 3.14f) * getRadianCargas(pos, pos2));
		angle2 = (_q[1]->q > 0 ? (180.0f / 3.14f) * getRadianCargas(pos2, pos) : (180.0f / 3.14f) * getRadianCargas(pos, pos2));
		_q[0]->q_angle = angle;
		_q[1]->q_angle = angle2;

		if (_q[0]->q > 0 && _q[1]->q > 0)
			_q[0]->q_angle = angle-180;
		else if (_q[0]->q < 0 && _q[1]->q < 0){
			_q[1]->q_angle = angle - 180;
		}else if (_q[0]->q < 0 && _q[1]->q > 0){
			_q[0]->q_angle = angle - 180;
			_q[1]->q_angle = angle2 - 180;
		}
		if (alter){
			alter = false;
			Force(_q[0], _q[1]);
		}
		_q[0]->interactive = true;
		_q[1]->interactive = true;
	}
	
	Node::Update();
}

void EletricField::CreateCarga(double q, int exp){
	if (length < MAX){
		_q[length] = new Carga(q,exp);
		_q[length]->setPos(100, 100);
		this->addChild(_q[length]);
		length++;
	}
}

void EletricField::Init(int max){
	Instance = new EletricField(max);
}

void EletricField::onSelectedCarga(float mouseX, float mouseY){
	for (int i = 0; i < length; i++){
		vec3 pos = _q[i]->getPos();
		float dx = pos.v[0] - mouseX;
		float dy = pos.v[1] - mouseY;
		float dist = sqrt((dx*dx) + (dy*dy));

		if (dist <= _q[i]->getRaio()+10){
			_q[i]->setPos(mouseX, mouseY);
			alter = true;
			break;
		}
	}
}

float EletricField::getRadianCargas(vec3 q, vec3 q2){
	float distX = q.v[0] - q2.v[0];
	float distY = q.v[1] - q2.v[1];
	float radian = atan2(distY, distX);
	return radian;
}

float EletricField::DistanceCargas(vec3 q, vec3 q2){
	float distX = q.v[0] - q2.v[0];
	float distY = q.v[1] - q2.v[1];
	return sqrt((distX * distX) + (distY*distY));
}

void EletricField::Force(Carga*q, Carga*q2){
	vec3 pos = q->getPos();
	vec3 pos2 = q2->getPos();
	float dist = DistanceCargas(pos, pos2) / 1000;
	double f = q->q * q2->q;
	f *= (f < 0 ? -1 : 1);
	int exp = q->exp + q2->exp;
	double force = K * (f*pow(10.0, exp) / (dist*dist));

	std::cout << "Force: " << force << std::endl;
	std::cout << "Ditance" << dist << std::endl;

	Force_2 = force;
	Dist_2 = dist;

	Graphic::Instance->addData(dist, force);

	//double campo = K * (q2->q * pow(10, q2->exp)) / (dist * dist);
	//std::cout << "Eletric Field:" << campo << std::endl;
}

void EletricField::ForceByDistance(Carga*q, Carga*q2, float distance){

}
