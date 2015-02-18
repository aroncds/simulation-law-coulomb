#version 400

uniform sampler2D texture;
in vec2 st;

out vec4 colorEnd;
vec4 result; 

void main(){
	result = texture2D(texture, st);
	
	if(result.r==0&&result.g==0&&result.b==0)
		discard;

	if(result.r==0.4&&result.g==0.4&&result.b==0.4)
		discard;

	//result = result * 0;

	colorEnd = result;
}