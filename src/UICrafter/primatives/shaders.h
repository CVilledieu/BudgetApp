#ifndef SHADERS_H
#define SHADERS_H

//Not the best solution as future shaders may need more, but that would cause a wasted space for the smaller shaders
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

typedef enum {
    MAIN,
} ShaderType;

typedef struct UniformInfo{
    UniformType uniform_type;
    DataType data_type;
    int location;
} UniformInfo;

typedef struct Shader{
    unsigned int id;
    ShaderType type;
    int uniform_count;
    UniformInfo uniforms[MAX_UNIFORM_COUNT];
} Shader;

void init_Shader(Shader* shader);
void set_uniform_data(UniformInfo* uni, void* data);
#endif