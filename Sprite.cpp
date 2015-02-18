#include "Sprite.h"

Sprite::Sprite(){

}

Sprite::Sprite(const char * file_name, int width, int height)
{
	_points = 4;
	TypeRender = GL_POLYGON;

	_obj = new GLfloat[12]{
		0.0f,0.0f,0.0f,
		(GLfloat)width,0.0f,0.0f,
		(GLfloat)width, (GLfloat)height, 0.0f,
		0.0f, (GLfloat)height, 0.0f
	};

	_color = new GLfloat[16]{
		1, 1, 1, 1,
			1, 1, 1, 1,
			1, 1, 1, 1,
			1, 1, 1, 1
	};

	_texCord = new GLfloat[8]{
		0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f
	};

	LoadTexture(file_name, width, height);

	createBuffers();
	createVertexBuffers();

	std::string t_vertex = ManagerAsset::loadShader("glsl//texture_vertex.glsl");
	std::string t_fragment = ManagerAsset::loadShader("glsl//texture_fragment.glsl");

	createShader(t_vertex.c_str(), GL_VERTEX_SHADER);
	createShader(t_fragment.c_str(), GL_FRAGMENT_SHADER);

	createProgram();
}

void Sprite::LoadTexture(const char * file_name, int width, int height){
	_textureID = ManagerAsset::TextureLoad(file_name, width, height);
}

void Sprite::createBuffers(){
	Geometry::createBuffers();

	glGenBuffers(1, &_textBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _textBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* (_points * 2), _texCord, GL_STATIC_DRAW);
}

void Sprite::createVertexBuffers(){
	Geometry::createVertexBuffers();

	glBindBuffer(GL_ARRAY_BUFFER, _textBuffer);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Sprite::Render(float * camera){
	BeginRender(camera);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureID);

	int location = glGetUniformLocation(_shaderProgram, "texture");
	glUniform1i(location, 0);
	
	EndRender();
}

void Sprite::Render(float * camera, mat4 parent){
	BeginRender(camera,parent);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureID);

	int location = glGetUniformLocation(_shaderProgram, "texture");
	glUniform1i(location, 0);

	EndRender();
}

Sprite::~Sprite(){
	Geometry::~Geometry();
	glDeleteBuffers(1, &_textBuffer);
}
