#include "lineitem.hpp"

/**
 *
 */
LineItem::LineItem(
    const QGraphicsItem* const firstItem,
    const QGraphicsItem* const secondItem
)
{
    const QRectF firstItemBounds = firstItem->boundingRect();
    setLine(
        firstItem->x() + firstItemBounds.width(),
        firstItem->y() + firstItemBounds.height(),
        secondItem->x(),
        secondItem->y()
    );
}
