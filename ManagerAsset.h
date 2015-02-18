/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Carregamento de imagens e codigos shaders

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#ifndef _MANAGERASSET_H_
#define _MANAGERASSET_H_

#include <iostream>
#include <map>
#include <fstream>
#include <string>

#include "GL\glew.h"
#include "GL\glut.h"

class ManagerAsset
{
private:
	static std::map<const char*, std::string> _shaders;
	static std::map<const char*, GLuint> _textures;
public:
	static std::string loadShader(const char * path);
	static GLuint TextureLoad(const char * file_name, int width, int height);
};

#endif
