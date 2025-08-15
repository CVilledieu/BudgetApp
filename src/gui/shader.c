const char *vert_shader_source = "#version 330 core \n"
"layout (location = 0) in vec3 aPos; \n"
"uniform mat4 view;\n"
"uniform mat4 model;\n"
"void main() {\n"
    "gl_Position = view * model * vec4(aPos, 1.0);\n"
"}\n";

const char *frag_shader_source = "#version 330 core \n"
"out vec4 FragColor;\n"
"uniform vec4 color;\n"
"void main() {\n"
    "FragColor = color;\n"
"}\n";

