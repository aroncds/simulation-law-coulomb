#version 400
in vec3 fcolor;

out vec4 color_final;

void main(){
	color_final = vec4(fcolor,1.0);
}