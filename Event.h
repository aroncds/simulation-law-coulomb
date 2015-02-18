/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Manipulação de eventos

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#ifndef _EVENT_H_
#define _EVENT_H_
#pragma once

#include <map>
#include <iostream>

class Event
{
private:
	std::map < std::string, std::map<int, void(*)()>> _events;
public:
	void addEvent(std::string type, void(*func)());
	void dispatchEvent(std::string type);
};
#endif

