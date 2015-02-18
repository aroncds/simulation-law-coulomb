#ifndef _BUTTON_H_
#define _BUTTON_H_

#pragma once
#include "Node.h"
#include "Quad.h"
#include "Event.h"
#include "Sprite.h"
enum MouseState { CLICK = 1, OVER, NORMAL };

class Button :
	public Node,public Event
{
private:
	void CreateButton(const char* normal, const char* over, const char* click, float width, float height);
	void changedState(MouseState state);
	int length = 0;
	float _width = 0;
	float _height = 0;
	Object **quads;
	MouseState mouseState;
	void(*_function_click)() = NULL;

public:
	Button(const char* normal, const char* over, const char* click, float width, float height);
	~Button();

	virtual bool Check(GLenum state, int x, int y) ;
	void addEventClick(void(*func) ());
};

#endif