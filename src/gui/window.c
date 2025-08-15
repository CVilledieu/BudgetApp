#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>



void callback_wndsize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


void callback_input(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS && action != GLFW_REPEAT) {
        return;
    }
    switch (key) {
        case GLFW_KEY_ESCAPE:
            break;
        default:
            
            break;
    }
    //Voiding unused parameters for compiler warnings
    (void)scancode;
	(void)mods;
}


GLFWwindow *wnd_init(char *title){
    if (!glfwInit()){
        printf("%s\n", "Failed to initialize GLFW");
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *Wnd_main = glfwCreateWindow(800, 600, title, NULL, NULL);
    if (!Wnd_main){
        printf("%s\n", "Failed to create GLFW window");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(Wnd_main);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("%s\n", "Failed to initialize GLAD");
        return NULL;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(Wnd_main, callback_wndsize);
    glfwSetKeyCallback(Wnd_main, callback_input);
    return Wnd_main;
}