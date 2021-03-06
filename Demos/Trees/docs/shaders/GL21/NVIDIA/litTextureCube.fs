#version 120 

uniform samplerCube mgTextureUnit0;

varying vec4 vFragColor;
varying vec3 vTex;

void main(void) 
{ 
  gl_FragColor = vFragColor * textureCube(mgTextureUnit0, vTex);
  if (gl_FragColor.a < 0.1)
    discard;
}
