#ifndef SHADERS_H
#define SHADERS_H

#define SHADER_PATH_FRAG ".shaders/main.frag.glsl"
#define SHADER_PATH_VERT ".shaders/main.vert.glsl"

#define MAX_SHADER_COUNT 16

typedef struct Shader_list{
    Shader shaders[MAX_SHADER_COUNT];
    int count;
} Shader_list;

typedef struct Shader{
    unsigned int id;
    int color_u_loc;
    int scale_u_loc;
    int pos_u_loc;
} Shader;

void Shader_create_id(Shader* shader);

#endif