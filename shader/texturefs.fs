precision mediump float;

varying vec2 v_texCoord;

void main(void)
{
	vec4 baseColor;
	vec4 lightColor;
	baseColor = texture2D(CC_Texture0, v_texCoord);
	lightColor = texture2D(CC_Texture1, v_texCoord);
	vec4 col = vec4(0, 1, 0, 1);
	//gl_FragColor = baseColor*lightColor;
	gl_FragColor = baseColor*(lightColor.r)+col*(1-lightColor.r);
	//gl_FragColor = baseColor;
}