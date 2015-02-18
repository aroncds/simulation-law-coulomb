#include "Graphic.h"

#define _MAX_DADOS 2000

Graphic * Graphic::Instance;

void Graphic::Init(int width, int height){
	Instance = new Graphic(width, height);
}

Graphic::Graphic(int width, int height):Node(6)
{
	this->width = width;
	this->height = height;

	dist = (double*)calloc(_MAX_DADOS, sizeof(double));
	force = (double*)calloc(_MAX_DADOS, sizeof(double));
	points = (double*)calloc(_MAX_DADOS*3, sizeof(double));

	_lines = (Line **)calloc(2,sizeof(Line));

	_lines[0] = new Line(0, height, 0, width, height, 0,0);
	_lines[1] = new Line(0, 0, 0, 0, height, 0, 0);
	current = new Circle(5, 15, 0, 1, 0);
}


Graphic::~Graphic()
{
	Node::~Node();
}

void Graphic::addData(double dist, double force){
	if (quantData < _MAX_DADOS){
		this->dist[quantData] = dist;
		this->force[quantData] = force;
		quantData++;
	}
}

void Graphic::Update(){
	if (generate)
		current->Position = vec3(((EletricField::Dist_2 * width) / dist[distMax]) * this->Scale.v[0], ((((EletricField::Force_2 * height) / force[forceMax])* -1) + height) *this->Scale.v[1], 0);

	current->visible = true;

	if (current->Position.v[1] < 0)
		current->visible = false;
	else if (current->Position.v[0] > width *this->Scale.v[0])
		current->visible = false;

	Node::Update();
}

void Graphic::generateGraphic(){
	Clear();

	for (int i = 0; i < quantData; i++){
		if (force[forceMax] < force[i]){
			forceMax = i;
		}
		if (dist[distMax] < dist[i]){
			distMax = i;
		}
	}

	p = new Point(false);
	p->quantPoint(quantData);
	
	for (int i = 0; i < quantData; i++){
		float x, y;
		x = (dist[i] * width) / dist[distMax];
		y = (((force[i] * height)/force[forceMax]) * -1) + height;
		p->addPoint(x, y, 0);
		p->addColor(0, 0, 0);
	}

	p->createBasic();
	p->TypeRender = GL_LINE_STRIP;

	generate = true;

	Quad * quad = new Quad(width + 50, height + 50, 1, 1, 1);
	quad->Position = vec3(-25, -25, 0);

	Quad * border = new Quad(width + 50, height + 50, 0, 0, 0);
	border->Position = vec3(-25, -25, 0);
	border->TypeRender = GL_LINE_LOOP;
	
	this->addChild(quad);
	this->addChild(border);
	this->addChild(_lines[0]);
	this->addChild(_lines[1]);
	this->addChild(p);
	this->addChild(current);
}
