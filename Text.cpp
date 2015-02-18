#include "Text.h"


Text::Text() :Sprite()
{
	LoadTexture("imagens/font.raw", 256, 256);
	TypeRender = GL_QUADS;
}


Text::~Text()
{
	Geometry::~Geometry();
}

void Text::createBuffers(){

	glGenBuffers(1, &_bufferObj);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferObj);
	glBufferData(GL_ARRAY_BUFFER, (_points * 2) * sizeof(GLfloat), _obj, GL_STATIC_DRAW);

	free(_obj);

	glGenBuffers(1, &_bufferColor);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferColor);
	glBufferData(GL_ARRAY_BUFFER, (_points * 2) * sizeof(GLfloat), _texCord, GL_STATIC_DRAW);

	free(_texCord);
}

void Text::UpdateBuffer(){
	glBindBuffer(GL_ARRAY_BUFFER, _bufferObj);
	glBufferData(GL_ARRAY_BUFFER, (_points * 2) * sizeof(GLfloat), _obj, GL_STATIC_DRAW);

	free(_obj);

	glBindBuffer(GL_ARRAY_BUFFER, _bufferColor);
	glBufferData(GL_ARRAY_BUFFER, (_points * 2) * sizeof(GLfloat), _texCord, GL_STATIC_DRAW);

	free(_texCord);
}

void Text::createVertexBuffers(){
	glGenVertexArrays(1, &_vertex);
	glBindVertexArray(_vertex);

	glBindBuffer(GL_ARRAY_BUFFER, _bufferObj);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, _bufferColor);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Text::InsertText(const char * _text, int width, int height){
	_length = strlen(_text);
	_points = _length * 4;

	_obj = (float*)malloc(sizeof (float)* _points * 2);
	_texCord = (float*)malloc(sizeof (float)* _points * 2);

	for (int i = 0; i < _length; i++){
		TextAtlas(_text[i], width, height);
	}

	if (!createBuffer){
		newBuffer();
		createBuffer = true;
	}
	//else// UpdateBuffer();
}

void Text::newBuffer(){
	createBuffers();
	createVertexBuffers();

	std::string text_vertex = ManagerAsset::loadShader("glsl/text_vertex.glsl");
	std::string text_fragment = ManagerAsset::loadShader("glsl/text_fragment.glsl");

	createShader(text_vertex.c_str(), GL_VERTEX_SHADER);
	createShader(text_fragment.c_str(), GL_FRAGMENT_SHADER);

	createProgram();
}

void Text::TextAtlas(int code, int width,int height){
	int currentPos = code - ' ';

	float TileWidth = (float)(252 / 10)/251;
	float TileHeight = (float)(252 / 10) / 251;

	int atlas_col = currentPos % 10;
	int atlas_row = currentPos / 10;

	_obj[add] = ((add / 8)*width) *0.4; 
	_obj[add + 1] = 0;

	_obj[add + 2] = (((add / 8)*width) + width) *0.4;
	_obj[add + 3] = 0;

	_obj[add + 4] = (((add / 8)*width) + width) *0.4;
	_obj[add + 5] = height;

	_obj[add + 6] = ((add / 8)*width) *0.4;
	_obj[add + 7] = height;


	_texCord[add] = (TileWidth * atlas_col) + 0.009;
	_texCord[add + 1] = TileHeight * atlas_row + 0.009;
	
	_texCord[add + 2] = (TileWidth * atlas_col) + TileWidth *0.4;
	_texCord[add + 3] = (TileHeight*atlas_row) + 0.009;

	_texCord[add + 4] = (TileWidth * atlas_col) + TileWidth *0.4;
	_texCord[add + 5] = (TileHeight*atlas_row) + TileHeight - 0.009;

	_texCord[add + 6] = (TileWidth*atlas_col) + 0.009;
	_texCord[add + 7] = (TileHeight*atlas_row) + TileHeight - 0.009;


	add += 8;
}