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
 * The type T is a list structure, it must contains:
 * getSize(),
 * getData()
 *
 */
template<typename T>
void render(
    QGraphicsScene* scene,
    T* structure
);

#endif
