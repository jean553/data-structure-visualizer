#ifndef LINEITEM_H_
#define LINEITEM_H_

#include <memory>

class QGraphicsScene;
class QGraphicsItem;

class LineItem
{

public:

    /**
     * @brief line item constructor
     *
     * @param scene the scene used for rendering
     * @param firstItem the item at the left side of the line
     * @param secondItem the item at the right side of the line
     *
     * TODO: #57 the line item should be an arrow;
     * the double linked list should use another line type
     */
    LineItem(
        QGraphicsScene* const scene,
        const QGraphicsItem* const firstItem,
        const QGraphicsItem* const secondItem
    );

    /**
     * @brief default destructor
     */
    ~LineItem();

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
