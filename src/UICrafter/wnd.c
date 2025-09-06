#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "crafter.h"

static void resize_cb(GLFWwindow* wnd, int width, int height) {
    UICtx* ctx = (UICtx*)glfwGetWindowUserPointer(wnd);
    ctx->wnd_height = height;
    ctx->wnd_width = width;
    glViewport(0, 0, width, height);
}

static void keypress_cb(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS && action != GLFW_REPEAT) {
        return;
    }
    switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window,1);
            break;
        default:
            
            break;
    }
    //Voiding unused parameters for compiler warnings
    (void)scancode;
	(void)mods;
}

void WndCtx_init(UICtx* ctx){
    if (!glfwInit()){
        printf("%s\n", "Failed to initialize GLFW");
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* new_wnd = glfwCreateWindow(ctx->wnd_width, ctx->wnd_height, ctx->wnd_title, NULL, NULL);
    if (!new_wnd){
        printf("%s\n", "Failed to create GLFW window");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(new_wnd);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("%s\n", "Failed to initialize GLAD");
        return NULL;
    }
    
    glViewport(0, 0, ctx->wnd_width, ctx->wnd_height);

    glfwSetWindowUserPointer(new_wnd, ctx);
    glfwSetFramebufferSizeCallback(new_wnd, resize_cb);
    glfwSetKeyCallback(new_wnd, keypress_cb);

    ctx->wnd = new_wnd;
}