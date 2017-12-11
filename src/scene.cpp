#include "scene.hpp"
#include "linkedlistitem.hpp"

#include "linked_list.h"

class Scene::Impl
{

public:

    LinkedList list;
};

/**
 *
 */
Scene::Scene() : impl(std::make_unique<Impl>())
{
}

/**
 *
 */
Scene::~Scene() = default;

/**
 *
 */
void Scene::createLinkedList(const int& data)
{
    LinkedListItem* item = new LinkedListItem(data);
    addItem(item);

    impl->list = create(data);
}
