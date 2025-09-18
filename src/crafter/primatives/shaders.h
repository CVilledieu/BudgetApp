#ifndef SHADERS_H
#define SHADERS_H

//Not the best solution as future shaders may need more, but that would cause a wasted space for the smaller shaders
#define MAX_UNIFORM_COUNT 3

#define SHADER_PATH_FRAG "./shaders/main.frag.glsl"
#define SHADER_PATH_VERT "./shaders/main.vert.glsl"

#define COLOR_UNIFORM "u_color"
#define MODEL_UNIFORM "u_model"
#define VIEW_UNIFORM "u_view"

typedef float Vec2[2];
typedef float Vec4[4];
typedef float Mat4[16];

typedef enum {
    VEC2,
    VEC4,
    MAT4,
} DataType;

typedef enum {
    COLOR, 
    MODEL,
    VIEW,
} UniformType;

typedef struct UniformInfo{
    UniformType uniform_type;
    DataType data_type;
    int location;
} UniformInfo;

typedef enum {
    BASIC,
    SHADER_COUNT,
} ShaderType;

typedef struct Shader{
    unsigned int id;
    ShaderType type;
    int uniform_count;
    UniformInfo uniforms[MAX_UNIFORM_COUNT];
} Shader;

void init_Shader(Shader* shader, ShaderType s_type);
void set_uniform_data(UniformInfo* uni, void* data);


#endif