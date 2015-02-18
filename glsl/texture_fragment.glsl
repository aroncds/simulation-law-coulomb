#version 400

in vec4 outColor;
in vec2 tex_cord;
uniform sampler2D texture;

vec4 color;

out vec4 colorEnd;

void main(){
	color = texture2D(texture, tex_cord) *outColor;

	if(color.r == 0.8 && color.g == 0 && color.b == 0.8)
		discard;

	colorEnd = color;
}