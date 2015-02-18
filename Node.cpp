#include "Node.h"

Node::Node(int quant_objects)
{
	length = quant_objects;
	_objects = (Object **)calloc(quant_objects, sizeof(Object));
}

void Node::addChild(Object *obj){
	if (quantAdd < length){
		_objects[quantAdd] = obj;
		quantAdd++;
	}
}

void Node::Update(){
	for (int i = 0; i < quantAdd; i++){
		_objects[i]->Update();
	}
}

void Node::Clear(){
	_objects = (Object **)calloc(length, sizeof(Object));
	quantAdd = 0;
}

void Node::Render(float* camera){
	mat4 result = translate(identity_mat4(), Position) * scale(identity_mat4(), Scale);
	for (int i = 0; i < quantAdd; i++){
		if (_objects[i]->visible)
			_objects[i]->Render(camera, result);
	}
}
void Node::Render(float* camera, mat4 parent){
	mat4 result = (translate(identity_mat4(), Position) * scale(identity_mat4(), Scale)*parent);
	for (int i = 0; i < quantAdd; i++){
		if (_objects[i]->visible)
			_objects[i]->Render(camera, result);
	}
}

Node::~Node()
{
}

