#ifndef LINEITEM_H_
#define LINEITEM_H_

#include <QGraphicsLineItem>

class LineItem : public QGraphicsLineItem
{

public:

    /**
     * @brief line item constructor
     *
     * @param firstItem the item at the left side of the line
     * @param secondItem the item at the right side of the line
     */
    LineItem(
        const QGraphicsItem* const firstItem,
        const QGraphicsItem* const secondItem
    );
};

#endif
