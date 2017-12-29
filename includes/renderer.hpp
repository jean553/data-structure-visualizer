#ifndef RENDERER_H_
#define RENDERER_H_

class LinkedListHandler;
class QGraphicsScene;

/**
 * @brief clears the scene and renders the given item
 *
 * @param scene the scene to use for rendering
 * @param structure the structure to render
 *
 * FIXME: use template to render any kind of list;
 * maybe rename the parameter structure to list
 * and the function name from render to renderList
 */
void render(
    QGraphicsScene* scene,
    LinkedListHandler* structure
);

#endif
