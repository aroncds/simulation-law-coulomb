#include "Geometry.h"

void Geometry::Update(){
	_matrix = translate(identity_mat4(), Position) * scale(identity_mat4(), Scale) * rotate_z_deg(identity_mat4(), Rotation.v[2]);
}

void Geometry::Render(float * camera){
	BeginRender(camera);
	EndRender();
}
void Geometry::BeginRender(float * camera, mat4 parent){
	int location_world = glGetUniformLocation(_shaderProgram, "world");
	int location_obj = glGetUniformLocation(_shaderProgram, "matrix_obj");
	mat4 result = _matrix * parent;
	glUseProgram(_shaderProgram);
	glUniformMatrix4fv(location_obj, 1, false, result.m);
	glUniformMatrix4fv(location_world, 1, false, camera);
	glBindVertexArray(_vertex);
}

void Geometry::BeginRender(float * camera){
	int location_world = glGetUniformLocation(_shaderProgram, "world");
	int location_obj = glGetUniformLocation(_shaderProgram, "matrix_obj");
	glUseProgram(_shaderProgram);
	glUniformMatrix4fv(location_obj, 1, false, _matrix.m);
	glUniformMatrix4fv(location_world, 1, false, camera);
	glBindVertexArray(_vertex);
}

void Geometry::EndRender(){
	glDrawArrays(TypeRender, 0, _points);
}

void Geometry::Render(float * camera, mat4 parent){
	BeginRender(camera, parent);
	EndRender();
}

Geometry::~Geometry(){
	glDeleteBuffers(1, &_bufferObj);
	glDeleteBuffers(1, &_bufferColor);
	glDeleteVertexArrays(1, &_vertex);
	glDeleteShader(_shaderVs);
	glDeleteShader(_shaderFs);
	glDeleteProgram(_shaderProgram);
}

void Geometry::createBuffers(){
	glGenBuffers(1, &_bufferObj);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferObj);
	glBufferData(GL_ARRAY_BUFFER, (_points * 3) * sizeof(GLfloat), _obj, GL_STATIC_DRAW);
	free(_obj);

	glGenBuffers(1, &_bufferColor);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferColor);
	glBufferData(GL_ARRAY_BUFFER, (_points * 4) * sizeof(GLfloat), _color, GL_STATIC_DRAW);
	free(_color);
}

void Geometry::createVertexBuffers(){
	glGenVertexArrays(1, &_vertex);
	glBindVertexArray(_vertex);

	glBindBuffer(GL_ARRAY_BUFFER, _bufferObj);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, _bufferColor);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Geometry::createShader(const char * shader, GLenum type){
	int params = -1;
	if (type == GL_VERTEX_SHADER){
		_shaderVs = glCreateShader(type);
		glShaderSource(_shaderVs, 1, &shader, NULL);
		glCompileShader(_shaderVs);

		glGetShaderiv(_shaderVs, GL_SHADER_COMPILER, &params);
		if (params != GL_TRUE){
			char vsLog[1024];
			glGetShaderInfoLog(_shaderVs, 1024, 0, vsLog);
			std::cout << vsLog << std::endl;
		}
	}
	else if (type == GL_FRAGMENT_SHADER){
		_shaderFs = glCreateShader(type);
		glShaderSource(_shaderFs, 1, &shader, NULL);
		glCompileShader(_shaderFs);

		glGetShaderiv(_shaderFs, GL_SHADER_COMPILER, &params);
		if (params != GL_TRUE){
			char vsLog[1024];
			glGetShaderInfoLog(_shaderFs, 1024, 0, vsLog);
			std::cout << vsLog << std::endl;
		}
	}
}

void Geometry::createProgram(){
	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, _shaderVs);
	glAttachShader(_shaderProgram, _shaderFs);
	glLinkProgram(_shaderProgram);

	int params = -1;
	glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &params);

	if (params != GL_TRUE){
		int actual_length = 0;
		int max_length = 2048;
		char log[2048];
		glGetProgramInfoLog(_shaderProgram, 2048, &actual_length, log);
		std::cout << log;
	}
}

void Geometry::createBasic(){
	createBuffers();
	createVertexBuffers();

	std::string vertex = ManagerAsset::loadShader("glsl/obj_vertex.glsl");
	std::string fragment = ManagerAsset::loadShader("glsl/obj_fragment.glsl");

	createShader(vertex.c_str(), GL_VERTEX_SHADER);
	createShader(fragment.c_str(), GL_FRAGMENT_SHADER);

	createProgram();
}
