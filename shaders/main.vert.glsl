#version 330 core
layout (location = 0) in vec2 a_Pos;

uniform vec2 u_translate;
uniform vec2 u_scale;

void main()
{  
    vec2 scaled = a_Pos * u_scale;
    vec2 transformed = scaled + u_translate;
    gl_Position = vec4(transformed, 0.0, 1.0);

}