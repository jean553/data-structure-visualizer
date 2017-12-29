#include "renderer.hpp"
#include "linkedlistitem.hpp"
#include "lineitem.hpp"
#include "linkedlisthandler.hpp"

#include <QGraphicsScene>
#include <QPointer>

/**
 *
 */
void render(
    QGraphicsScene* scene,
    LinkedListHandler* structure
)
{
    scene->clear();

    const auto length = structure->getSize();

    qreal horizontalPosition {10.0};
    qreal verticalPosition {10.0};

    QPointer<LinkedListItem> lastItem;

    for (
        auto index = 0;
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
