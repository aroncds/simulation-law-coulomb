/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Criar uma janela de input, para inserir dados de força

(not completed)

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#ifndef _INPUT_H_
#define _INPUT_H_
#include <Windows.h>
#include <iostream>
#include <string>

class Input 
{
private:
	HWND _input;
public:
	static HINSTANCE Hinst;
	static HWND window;
	static Input * Instance;
	static void Init(HINSTANCE inst, HWND win);

	void createWindow();
	void closeWindow();
	std::string sendResult();
	Input();
	~Input();
};

#endif