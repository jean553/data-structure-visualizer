#include "scene.hpp"
#include "linkedlistitem.hpp"

/**
 *
 */
Scene::Scene()
{
}

/**
 *
 */
void Scene::createLinkedList()
{
    /* TODO: 0 by default for now, the user should choose */
    LinkedListItem* item = new LinkedListItem(0);
    addItem(item);
}
