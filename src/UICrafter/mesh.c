//Mesh should be initialized near at start up
//The Mesh should then be refrenced for each Widget using that MeshType
//This should reduce the number of Meshes and shaders created
//Due to currently only having 1 MeshType so I have avoided unnecessary complexity 
//Once additional Meshtpes are needed many functions will be updated to handle them
//Areas that are expected to be updated with MeshTyping have been noted as such

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "mesh.h"
#include <stdio.h>
#include <stdlib.h>

//Forward declarations
static void create_VertexData(VertexObject* vo);
static void init_Shaders(Shader* shader);

//Pending MeshTyping
Mesh* init_Mesh(MeshType type){
    Mesh* mesh = malloc(sizeof(Mesh));
    mesh->mType = SQUARE;
    create_VertexData(mesh->VO);
    init_Shaders(mesh->shader);
    return mesh;
}

//Pending MeshTyping
void render_Mesh(Mesh* mesh){
    glBindVertexArray(mesh->VO->VAO);
    glDrawElements(GL_TRIANGLES, mesh->VO->index_count,GL_UNSIGNED_INT, 0);
}

//Pending MeshTyping
static void create_VertexData(VertexObject* vo){
    float vertices[] = {
        0.0f, 0.0f,   0.5f, 0.0f,   0.0f,-0.5f,   0.5f, -0.5f
    };
    unsigned int indices[] = {
        0,1,2,  1,2,3
    };

    glGenBuffers(1, vo->EBO);
    glGenBuffers(1, vo->VBO);
    glGenVertexArrays(1, vo->VAO);
    glBindVertexArray(vo->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, vo->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vo->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    vo->index_count = sizeof(indices) / sizeof(unsigned int);

    glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}


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
static void init_Shaders(Shader* shader){
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
    shader->color_u_loc = glGetUniformLocation(shader->id, "u_color");
    shader->view_u_loc  = glGetUniformLocation(shader->id, "u_view");
    shader->model_u_loc = glGetUniformLocation(shader->id, "u_model");
}

void set_uniform(unsigned int location, void* data, UniformType type){
        switch (type) {
        case UT_VEC4:
            glUniform4fv(location, 1, (float*)data);
            break;
        case UT_MAT4:
            glUniformMatrix4fv(location, 1, GL_FALSE, (float*)data);
            break;
    }
}