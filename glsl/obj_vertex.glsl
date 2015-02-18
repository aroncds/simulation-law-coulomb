#version 400

layout(location=0) in vec3 pos;
layout(location=1) in vec3 color;

uniform mat4 world, matrix_obj;
out vec3 fcolor;

void main(){
	gl_Position = (world * matrix_obj) * vec4(pos,1.0);
	fcolor = color;
}