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
void Scene::createLinkedList(const int& data)
{
    LinkedListItem* item = new LinkedListItem(data);
    addItem(item);
}
