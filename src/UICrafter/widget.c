#include "widget.h"

static void draw(RenderData* rend_data);

Widget* Widget_create(Widget_Type type){
    Widget* new = malloc(sizeof(Widget));
    switch(type){
        case CONTAINER_TYPE_CANVAS:
            break;
        case CONTAINER_TYPE_CONTAINER:
            break;
        case CONTAINER_TYPE_BUTTON:
            break;
    }
    return new;
}

