/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Manipulação de texto no contexto do opengl
(not completed)

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#pragma once
#include "Sprite.h"

class Text :
	public Sprite
{
private:
	std::string _text;
	int _length = 0;
	GLfloat * _texCord;
	void TextAtlas(int code, int width, int height);
	int add = 0;
	bool createBuffer = false;
	void newBuffer();

	
protected:
	virtual void createBuffers() override;
	virtual void createVertexBuffers() override;


public:
	Text();
	~Text();
	void UpdateBuffer();

	//virtual void Update() override;
	//virtual void Render(float * camera) override;
	//virtual void Render(float * camera, mat4 parent) override;
	void InsertText(const char* _text, int width, int height);
};

