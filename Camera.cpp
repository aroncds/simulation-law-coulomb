#include "Camera.h"

Camera::Camera()
{

}

void Camera::setOrtographic(float l, float r, float t, float b, float n, float f){
	_projection = new GLfloat[16]{
		2 / (r - l), 0.0f, 0.0f, 0.0f,
			0.0f, 2 / (t - b), 0.0f, 0.0f,
			0.0f, 0.0f, -1 / (f - n), 0.0f,
			-(r + l) / (r - l), -(t + b) / (t - b), -n / (f - n), 1.0f
	};
	
}

void Camera::setProjection(){

}

float* Camera::getMatrix(){
	return _projection;
}

Camera::~Camera()
{
}
