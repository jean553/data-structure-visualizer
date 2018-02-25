#include "renderer.hpp"
#include "linkedlistitem.hpp"
#include "lineitem.hpp"
#include "linkedlisthandler.hpp"
#include "doublelinkedlisthandler.hpp"
#include "arrayhandler.hpp"

#include <QGraphicsScene>
#include <QPointer>

/**
 *
 */
template<typename T>
void render(
    QGraphicsScene* scene,
    T* structure
)
{
    scene->clear();

    const auto length = structure->getSize();

    qreal horizontalPosition {10.0};
    qreal verticalPosition {10.0};

    QPointer<LinkedListItem> lastItem;

    for (
        unsigned int index = 0;
        index < length;
        index += 1
    ) {

        const auto data = structure->getData(index);

        constexpr qreal ITEMS_DISTANCE {50.0};
        horizontalPosition += ITEMS_DISTANCE;
        verticalPosition += ITEMS_DISTANCE;

        LinkedListItem* item = new LinkedListItem(data);
        item->setPos(
            horizontalPosition,
            verticalPosition
        );

        if (not lastItem.isNull())
        {
            LineItem* line = new LineItem(
                lastItem,
                item
            );

            scene->addItem(line);
        }

        scene->addItem(item);

        lastItem = item;
    }
}

/**
 *
 */
template void render<LinkedListHandler>(
    QGraphicsScene* scene,
    LinkedListHandler* structure
);

/**
 *
 */
template void render<DoubleLinkedListHandler>(
    QGraphicsScene* scene,
    DoubleLinkedListHandler* structure
);

/**
 *
 */
void renderArray(
    QGraphicsScene* scene,
    const ArrayHandler* arrayHandler
)
{
    scene->clear();

    qreal verticalPosition {10.0};

    const auto amount = arrayHandler->getAmount(); 

    for (
        unsigned int index = 0;
        index < amount;
        index += 1
    ) {

        const auto data = arrayHandler->getData(index);
        LinkedListItem* item = new LinkedListItem(data);

        constexpr qreal ITEMS_HORIZONTAL_POSITION {10.0};
        constexpr qreal ITEMS_DISTANCE {25.0};
        verticalPosition += ITEMS_DISTANCE;
        item->setPos(
            ITEMS_HORIZONTAL_POSITION,
            verticalPosition
        );

        scene->addItem(item);
    }
}
