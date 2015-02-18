/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Manipulação de textures 2D com o opengl

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Geometry.h"

class Sprite :
	public Geometry
{

protected:
	GLfloat * _texCord;
	virtual void createVertexBuffers() override;
	virtual void createBuffers() override;
	void LoadTexture(const char * file_name, int width, int height);
	GLuint _textureID;
	GLuint _textBuffer;

public:
	Sprite(const char * file_name, int width, int height);
	Sprite();
	virtual void Render(float * camera) override;
	virtual void Render(float * camera, mat4 parent) override;
	~Sprite();
};

#endif