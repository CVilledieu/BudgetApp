//
//
//
//
//
#include "wnd.h"

static void resize_cb(GLFWwindow* wnd, int new_width, int new_height) {
    WndCtx* ctx = (WndCtx*)glfwGetWindowUserPointer(wnd);
    ctx->height = new_height;
    ctx->width = new_width;
    glViewport(0, 0, new_width, new_height);
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

static void create_wnd(WndCtx* ctx){
    if (!glfwInit()){
        printf("%s\n", "Failed to initialize GLFW");
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* new_wnd = glfwCreateWindow(ctx->width, ctx->height, ctx->title, NULL, NULL);
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
    
    glViewport(0, 0, ctx->width, ctx->height);

    glfwSetWindowUserPointer(new_wnd, ctx);
    glfwSetFramebufferSizeCallback(new_wnd, resize_cb);
    glfwSetKeyCallback(new_wnd, keypress_cb);

    ctx->wnd = new_wnd;
}

WndCtx* init_WndCtx(char* title, int height, int width){
    WndCtx* new = malloc(sizeof(WndCtx));
    new->title;
    new->height = height;
    new->width = width;
    create_wnd(new);
    return new;
}