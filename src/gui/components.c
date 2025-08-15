// Elements are the core parts of the gui system.
// List of elements:
//  Frame
//  Panel
//  Container

// Frames build into Panels, Panels are then built into Containers
// Containers are then used to create Buttons and other elements.


#include <stdlib.h>
#include "components.h"


Container *Container_Create(Container *parent) {
    Container *container = (Container *)malloc(sizeof(Container));
    if (parent == NULL) {
        container->parent = NULL;
    } else {
        container->parent = parent;
    }
    return container;
}

void Draw_Frame(Frame *frame) {
    glBindVertexArray(frame->VAO);
    glDrawElements(GL_TRIANGLES, frame->Size, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}