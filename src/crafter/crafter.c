//
//Crafter acts as the layout manager.
//Crafter takes in coordinates relative to an origin that is in the upper left and then normalizes them to screen coordinates for OpenGl
//
#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "wnd.h"
#include "crafter.h"



static void prep_buffer(Vec4 color);
static void swap_buffer(WndCtx* wc);


UICtx* init_UICtx(char* title){
    UICtx* uc = malloc(sizeof(UICtx));
    uc->wnd = init_WndCtx(title, 600, 800);
    init_Mesh_array(uc->meshes);
    return uc;
}



//Single step of a loop, so the app using the ui can have logic run each step also
void render(UICtx* uc){
    prep_buffer(uc->panel_color);

    swap_buffer(uc->wnd);
}

static void render_element(Widget* widget, Mesh* mesh, Mat4 view){}

