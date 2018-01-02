#include "lineitem.hpp"

#include <QGraphicsLineItem>
#include <QGraphicsScene>

class LineItem::Impl
{

public:

    Impl(
        QGraphicsScene* const scene,
        const QGraphicsItem* const firstItem,
        const QGraphicsItem* const secondItem
    )
    {
        const QRectF firstItemBounds = firstItem->boundingRect();

        line = new QGraphicsLineItem();
        line->setLine(
            firstItem->x() + firstItemBounds.width(),
            firstItem->y() + firstItemBounds.height(),
            secondItem->x(),
            secondItem->y()
        );

        scene->addItem(line);
    }

    QGraphicsLineItem* line;
};

/**
 *
 */
LineItem::LineItem(
    QGraphicsScene* const scene,
    const QGraphicsItem* const firstItem,
    const QGraphicsItem* const secondItem
) :
    impl(
        std::make_unique<Impl>(
            scene,
            firstItem,
            secondItem
        )
    )
{
}

/**
 *
 */
LineItem::~LineItem() = default;
