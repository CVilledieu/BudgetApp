#version 330 core
layout (location = 0) in vec2 Pos;

uniform mat4 u_view;
uniform mat4 u_model;

void main()
{  
    
    gl_Position = u_view * u_model * vec4(Pos, 0.0, 1.0);

}