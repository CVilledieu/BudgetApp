#include "crafter.h"


static void wndCB_resize(GLFWwindow* wnd, int width, int height) {
    WndCtx* ctx = (WndCtx*)glfwGetWindowUserPointer(wnd);
    ctx->height = height;
    ctx->width = width;
    glViewport(0, 0, width, height);
}

static void wndCB_keypress(GLFWwindow* window, int key, int scancode, int action, int mods) {
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




WndCtx* WndCtx_Init(char* title){
    WndCtx* WCtx = malloc(sizeof(WndCtx));
    WCtx->width = 800;
    WCtx->height = 600;

    if (!glfwInit()){
        printf("%s\n", "Failed to initialize GLFW");
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* new_wnd = glfwCreateWindow(WCtx->width, WCtx->height, title, NULL, NULL);
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
    
    glViewport(0, 0, WCtx->width, WCtx->height);

    glfwSetWindowUserPointer(new_wnd, WCtx);
    glfwSetFramebufferSizeCallback(new_wnd, wndCB_resize);
    glfwSetKeyCallback(new_wnd, wndCB_keypress);

    return WCtx;
}