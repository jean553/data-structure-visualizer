#include "scene.hpp"
#include "linkedlistitem.hpp"
#include "lineitem.hpp"

#include "linked_list.h"

class Scene::Impl
{

public:

    LinkedList list;

    qreal lastItemHorizontalPosition {10.0};
    qreal lastItemVerticalPosition {10.0};
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
void Scene::createLinkedList(const int& data) &
{
    LinkedListItem* item = new LinkedListItem(data);
    applyCurrentItemPosition(item);
    addItem(item);

    impl->list = create(data);

    increaseItemPositions();
}

/**
 *
 */
void Scene::insertAtTheEndLinkedList(const int& data) &
{
    LinkedListItem* item = new LinkedListItem(data);
    applyCurrentItemPosition(item);
    addItem(item);

    LineItem* line = new LineItem();
    addItem(line);

    insertAtTheEnd(
        &impl->list,
        data
    );

    increaseItemPositions();
}

/**
 *
 */
void Scene::applyCurrentItemPosition(QGraphicsTextItem* item) const &
{
    item->setPos(
        impl->lastItemHorizontalPosition,
        impl->lastItemVerticalPosition
    );
}

/**
 *
 */
void Scene::increaseItemPositions() const & noexcept
{
    constexpr qreal ITEMS_DISTANCE {50.0};
    impl->lastItemHorizontalPosition += ITEMS_DISTANCE;
    impl->lastItemVerticalPosition += ITEMS_DISTANCE;
}
