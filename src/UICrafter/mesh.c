#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "mesh.h"
#include <stdio.h>

//Forward declarations
static void Mesh_init(Mesh* mesh);
static void Shader_init(Shader* shader);


Shape* Shape_int(){
    Shape* new_shape = malloc(sizeof(Shape));
    new_shape->mesh = malloc(sizeof(Mesh));
    new_shape->shader = malloc(sizeof(Shader));
    Mesh_init(new_shape->mesh);    
}

static void Mesh_init(Mesh* mesh){
    float vertices[] = {
        0.0f, 0.0f,   0.5f, 0.0f,   0.0f,-0.5f,   0.5f, -0.5f
    };
    unsigned int indices[] = {
        0,1,2,  1,2,3
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

    return mesh;
}

#define SHADER_PATH_FRAG ".shaders/main.frag.glsl"
#define SHADER_PATH_VERT ".shaders/main.vert.glsl"


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

static void Shader_init(Shader* shader){
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
