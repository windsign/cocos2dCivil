attribute vec4 a_position;
attribute vec2 a_texCoord;

varying vec2 v_texCoord;

uniform vec4 u_pos;

void main(void)
{
	gl_Position = CC_MVPMatrix * (a_position + u_pos);
	v_texCoord = a_texCoord;
}