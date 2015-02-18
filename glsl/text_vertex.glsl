#version 400

layout(location=0) in vec2 vp;
layout(location=1) in vec2 vt;

uniform mat4 world, matrix_obj;

out vec2 st;

void main(){
	st = vt;
	gl_Position = (world * matrix_obj) * vec4(vp, 0.0,1.0);
}