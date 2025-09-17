#ifndef SHADERS_H
#define SHADERS_H

#define MAX_UNIFORM_COUNT 3

typedef enum {
    COLOR, 
    MODEL,
    VIEW,
} UniformType;

typedef enum {
    VEC2,
    VEC4,
    MAT4,
} DataType;

typedef struct UniformInfo{
    UniformType uniform_type;
    DataType data_type;
    int location;
} UniformInfo;

typedef struct Shader{
    unsigned int id;
    int uniform_count;
    UniformInfo uniforms[MAX_UNIFORM_COUNT];
} Shader;

void init_Shader(Shader* shader);
void set_uniform_data(UniformInfo* uni, void* data);
#endif