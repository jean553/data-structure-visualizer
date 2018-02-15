#ifndef RENDERER_H_
#define RENDERER_H_

class LinkedListHandler;
class ArrayHandler;
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

/**
 * @brief clears the scene and renders the array of the given array handler,
 * pass the whole array handler as size is necessary (the array is a raw array)
 *
 * @param scene the scene to use for rendering
 * @param arrayHandler the array handler where the array is located
 */
void renderArray(
    QGraphicsScene* scene,
    const ArrayHandler* arrayHandler
);

#endif
