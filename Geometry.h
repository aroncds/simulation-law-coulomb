#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#pragma once
#include "Object.h"

class Geometry :public Object
{
protected:
	GLfloat * _obj;
	GLfloat * _color;
	GLuint _bufferObj;
	GLuint _bufferColor;
	GLuint _vertex;
	GLuint _shaderVs;
	GLuint _shaderFs;
	GLuint _shaderProgram;
	float _points = 0.0f;
	float _extraPoints = 0.0f;
	mat4 _matrix;
	virtual void createVertexBuffers();
	virtual void createBuffers();
	void createShader(const char * shader, GLenum type);
	void createProgram();
public:
	int TypeRender = GL_LINES;
	virtual void BeginRender(float * camera);
	virtual void BeginRender(float * camera, mat4 parent);
	virtual void EndRender();
	virtual void Update() override;
	virtual void Render(float * camera) override;
	virtual void Render(float * camera, mat4 parent) override;
	void createBasic();
	~Geometry();
};

#endif

