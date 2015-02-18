#version 400

layout(location=0) in vec3 pos;
layout(location=1) in vec3 color;
layout(location=2) in vec2 texture_cord;

uniform mat4 world, matrix_obj;

out vec4 outColor;
out vec2 tex_cord;

void main(){
	gl_Position = (world * matrix_obj) * vec4(pos,1.0);
	tex_cord = texture_cord;
	outColor = vec4(color,1.0);
}