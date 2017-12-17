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
const unsigned int& Scene::getLinkedListLastIndex() const &
{
    return ::size(&impl->list) - 1;
}

/**
 *
 */
void Scene::selectItem(const int& index) &
{
    constexpr int LINKED_LIST_NODES_STEPS {2};

    auto allItems = items(Qt::AscendingOrder);
    const auto length = allItems.size();

    /* we want to iterate to each linked list node to another,
       each one is separated by a step; handle this is easier
       with a for loop rather than an iterator */
    for (
        auto i = 0;
        i < length;
        i += LINKED_LIST_NODES_STEPS
    ) {
        /* undefined behaviour if at(i) does not contain a pointer to a LinkedListItem*;
           in case of a linked list, this situation should not happen */
        auto currentItem = static_cast<LinkedListItem*>(allItems.at(i));

        constexpr int UNSELECTED_COLOR_RED {0};
        constexpr int UNSELECTED_COLOR_GREEN {0};
        constexpr int UNSELECTED_COLOR_BLUE {0};
        constexpr int UNSELECTED_COLOR_ALPHA {255};
        currentItem->setDefaultTextColor(
            QColor(
                UNSELECTED_COLOR_RED,
                UNSELECTED_COLOR_GREEN,
                UNSELECTED_COLOR_BLUE,
                UNSELECTED_COLOR_ALPHA
            )
        );
    }

    /* undefined behaviour if at(i) does not contain a pointer to a LinkedListItem*;
       in case of a linked list, this situation should not happen */
    auto selectedItem = static_cast<LinkedListItem*>(
        allItems.at(index * LINKED_LIST_NODES_STEPS)
    );

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
