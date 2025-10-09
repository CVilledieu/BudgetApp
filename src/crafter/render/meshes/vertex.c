#include "mesh.h"

const float SQUARE_VERTICES[] = {
    //positions    //texture coords
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, //bottom left
    0.5f, 0.0f, 0.0f,   1.0f, 0.0f, //bottom right
    0.5f,-0.5f, 0.0f,   1.0f, 1.0f, //top right
    0.0f,-0.5f, 0.0f,   0.0f, 1.0f  //top left
};





const float TRIANGLE_VERTICES[] = {
    //positions    //texture coords
    0.0f, 0.0f, 0.0f,   0.5f, 1.0f, //top
   -0.5f,-0.5f, 0.0f,   0.0f, 0.0f, //bottom left
    0.5f,-0.5f, 0.0f,   1.0f, 0.0f  //bottom right
};

