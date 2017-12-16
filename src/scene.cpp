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
LinkedList& Scene::getLinkedList() const & noexcept
{
    return impl->list;
}

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
    /* this line may segfault if the items list is empty;
       we voluntary keep it as this function should not
       be called if the list is empty anyway */
    QGraphicsItem* previousItem = items(Qt::AscendingOrder).last();

    LinkedListItem* item = new LinkedListItem(data);
    applyCurrentItemPosition(item);

    LineItem* line = new LineItem(
        previousItem,
        item
    );

    addItem(line);
    addItem(item);

    insertAtTheEnd(
        &impl->list,
        data
    );

    increaseItemPositions();
}

/**
 *
 */
void Scene::selectItem(const int& index) &
{
    /* multiplied by 2 in order to bypass the arrows items */
    /* XXX: explain what happens here... */
    LinkedListItem* selectedItem = (LinkedListItem*) items(Qt::AscendingOrder).at(index * 2);

    constexpr int SELECTED_COLOR_RED {255};
    constexpr int SELECTED_COLOR_GREEN {0};
    constexpr int SELECTED_COLOR_BLUE {0};
    constexpr int SELECTED_COLOR_ALPHA {255};
    selectedItem->setDefaultTextColor(
        QColor(
            SELECTED_COLOR_RED,
            SELECTED_COLOR_GREEN,
            SELECTED_COLOR_BLUE,
            SELECTED_COLOR_ALPHA
        )
    );
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
