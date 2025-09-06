#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "mesh.h"
#include <stdio.h>
#include <stdlib.h>



#define SHADER_PATH_FRAG ".shaders/main.frag.glsl"
#define SHADER_PATH_VERT ".shaders/main.vert.glsl"

static unsigned int create(char *fName, GLenum type){
    	unsigned int shObj = glCreateShader(type);

	FILE *fp;
	fp = fopen(fName, "rb");
	if (fp == NULL){
			printf("%s\n", "failed to open shader file");
			glfwTerminate();
		}

	fseek(fp, 0, SEEK_END);
	long length = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *Src = (char *)malloc(length + 1);
	fread(Src, 1, length, fp);
	Src[length] = '\0';
	fclose(fp);

	const char *shSrc = Src;

	glShaderSource(shObj, 1, &shSrc, (void*)0);
	glCompileShader(shObj);

	int ok = 0;
	glGetShaderiv(shObj, GL_COMPILE_STATUS, &ok);
	if(!ok){
		glDeleteShader(shObj);
		printf("%s\n", "Shader failed to compile");
		glfwTerminate();
	}
	free(Src);
	return shObj;
}

unsigned int Shader_init(){
    unsigned int shader, frag, vert;
    frag = compile(SHADER_PATH_FRAG, GL_FRAGMENT_SHADER);
    vert = compile(SHADER_PATH_VERT, GL_VERTEX_SHADER);
    shader = glCreateProgram();
    glAttachShader(shader, frag);
    glAttachShader(shader, vert);
    glLinkProgram(shader);

    int ok;
    glGetProgramiv(shader, GL_LINK_STATUS, &ok);
    if (!ok){
        printf("%s\n", "Failed to compile shader");
        glfwTerminate();
    }
    glDeleteShader(frag);
    glDeleteShader(vert);
}


Mesh* Mesh_init(void){
    Mesh* mesh = malloc(sizeof(Mesh));

    float vertices[] = {
        0.5f, 0.5f,   0.5f, -0.5f,   -0.5f,-0.5f,   -0.5f, 0.5f
    };
    unsigned int indices[] = {
        0,1,3,  1,2,3
    };

    glGenBuffers(1, &mesh->EBO);
    glGenBuffers(1, &mesh->VBO);
    glGenVertexArrays(1, mesh->VAO);
    glBindVertexArray(mesh->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    mesh->index_count = sizeof(indices) / sizeof(unsigned int);

    glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    mesh->shader_id = Shader_init();
    mesh->color = malloc(sizeof(float) * 4);
    return mesh;
}


void Mesh_update_color(Mesh* mesh, float* color){
    mesh->color[0] = color[0];
    mesh->color[1] = color[1];
    mesh->color[2] = color[2];
    mesh->color[3] = color[3];
}

static void convert_color(){

}