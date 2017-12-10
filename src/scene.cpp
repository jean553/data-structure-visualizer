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
    LinkedListItem* item = new LinkedListItem();
    addItem(item);
}
