#include "glad/glad.h"
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
