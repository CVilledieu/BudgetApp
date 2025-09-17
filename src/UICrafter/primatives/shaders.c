//
//
//
//
//
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shaders.h"
#include <stdio.h>
#include <stdlib.h>


static void create_UniformInfo(UniformType u_type, DataType d_type, Shader* shader, char* name);

//Pending MeshTyping
#define SHADER_PATH_FRAG "./shaders/main.frag.glsl"
#define SHADER_PATH_VERT "./shaders/main.vert.glsl"


static unsigned int compile_shaders(char *fName, GLenum type){
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

	glShaderSource(shObj, 1, &shSrc, NULL);
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

//Pending MeshTyping
void init_Shader(Shader* shader){
    unsigned int frag, vert;
    frag = compile_shaders(SHADER_PATH_FRAG, GL_FRAGMENT_SHADER);
    vert = compile_shaders(SHADER_PATH_VERT, GL_VERTEX_SHADER);
    shader->id = glCreateProgram();
    glAttachShader(shader->id, frag);
    glAttachShader(shader->id, vert);
    glLinkProgram(shader->id);

    int ok;
    glGetProgramiv(shader->id, GL_LINK_STATUS, &ok);
    if (!ok){
        printf("%s\n", "Failed to compile shader");
        glfwTerminate();
    }
    glDeleteShader(frag);
    glDeleteShader(vert);
    shader->uniform_count = 0;
    create_UniformInfo(COLOR, VEC4, shader, "u_color");
    create_UniformInfo(MODEL, MAT4, shader, "u_shader");
    create_UniformInfo(VIEW, MAT4, shader, "u_view");

}

static void create_UniformInfo(UniformType u_type, DataType d_type, Shader* shader, char* name){
    UniformInfo new_Uniform;
    new_Uniform.data_type = d_type;
    new_Uniform.uniform_type = u_type;
    new_Uniform.location = glGetUniformLocation(shader->id, name);

    shader->uniforms[shader->uniform_count] = new_Uniform;
    shader->uniform_count++;
}

void set_uniform_data(UniformInfo* uni, void* data){
    switch (uni->data_type) {
        case VEC2:
            break;
        case VEC4:
            glUniform4fv(uni->location, 1, (float*)data);
            break;
        case MAT4:
            glUniformMatrix4fv(uni->location, 1, GL_FALSE, (float*)data);
            break;
        default:
            //catch errors
            break;
    }
}