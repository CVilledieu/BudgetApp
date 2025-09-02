#include <stdio.h>
#include <stdlib.h>
#include "crafter.h"



void UI_background(UICtx* ctx, float* color){
    ctx->bgColor[0] = color[0];
    ctx->bgColor[1] = color[1];
    ctx->bgColor[2] = color[2];
    ctx->bgColor[3] = color[3];
}

UICtx* UICtx_Init(char* title){
    UICtx* new_ctx = malloc(sizeof(UICtx));
    new_ctx->wnd = WndCtx_Init(title);
    
    new_ctx->bgColor = malloc(sizeof(float) * 4);
    UI_background(new_ctx, (float[]){1.0f, 1.0f, 1.0f, 1.0f});
    return new_ctx;
}

static void draw_init(float* bgColor){
    glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);
    glClear(GL_COLOR_BUFFER_BIT );
}

static void draw_end(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}

void Draw(UICtx* ctx){
    draw_init(ctx->bgColor);
    
    

    draw_end(ctx->wnd);
}

unsigned int vao_new_quad(){
    float vertices[] = {
        0.5f, 0.5f,
        0.5f, -0.5f,
        -0.5f,-0.5f,
        -0.5f, 0.5f
    };
    unsigned int indices[] = {
        0,1,3,1,2,3
    };

    unsigned VAO, VBO, EBO;
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return VAO;
}