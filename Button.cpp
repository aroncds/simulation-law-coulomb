#include "Button.h"

#define _QUANTIDADE_NODE_ 3

std::map<std::string, std::map<int, void(*)()>> events;

void Dahora(){

}

Button::Button(const char* normal, const char* over, const char* click, float width, float height) : Node(_QUANTIDADE_NODE_)
{
	_width = width;
	_height = height;
	CreateButton(normal,  over, click, width, height);

}

void Button::CreateButton(const char* normal, const char* over, const char* click, float width, float height){
	quads = (Object**)calloc(3, sizeof(Quad));
	quads[0] = new Sprite(normal, width, height);
	this->addChild(quads[0]);

	quads[1] = new Sprite(click, width, height);
	this->addChild(quads[1]);
	quads[1]->visible = false;

	quads[2] = new Sprite(over, width, height);
	this->addChild(quads[2]);
	quads[2]->visible = false;
}


bool Button::Check(GLenum state, int x, int y){
	if (Position.v[0] < x && Position.v[0] + (_width * this->Scale.v[0]) > x && Position.v[1] < y && Position.v[1] + (_height * this->Scale.v[1])> y){
		if (state == GLUT_DOWN){
			changedState(MouseState::CLICK);
			dispatchEvent("CLICK");
			return true;
		}else
			changedState(MouseState::OVER);
	}
	else if (state == GLUT_UP)
		changedState(MouseState::NORMAL);
	return false;
}

void Button::changedState(MouseState state){
	switch (state){
	case MouseState::CLICK:
		this->quads[0]->visible = false;
		this->quads[1]->visible = true;
		this->quads[2]->visible = false;
		break;
	case MouseState::OVER:
		quads[0]->visible = false;
		quads[1]->visible = false;
		quads[2]->visible = true;
		break;
	case MouseState::NORMAL:
		quads[0]->visible = true;
		quads[1]->visible = false;
		quads[2]->visible = false;
		break;
	}
}
void Button::addEventClick(void (* func)()){
	_function_click = func;
}


Button::~Button()
{
}
