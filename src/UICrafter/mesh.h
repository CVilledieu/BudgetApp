#ifndef MESH_H
#define MESH_H



typedef struct Shader{
    unsigned int id;
    int color_u_loc;
    int view_u_loc;
    int model_u_loc; 
} Shader;



typedef struct Mesh{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    int index_count;
}Mesh;

typedef float Mat4[16];

//Alt names 
//    Primitive
//    Drawable
//    GraphicObject
//    RenderItem
//    Frame
//    Shape

typedef struct Shape {
    Mesh* mesh;
    Shader* shader;
    Mat4 model;
} Shape;

#endif