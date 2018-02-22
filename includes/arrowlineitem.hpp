#ifndef ARROWLINEITEM_H_
#define ARROWLINEITEM_H_

#include <QGraphicsLineItem>

#include <memory>


class ArrowLineItem : public QGraphicsLineItem
{
public:
    /**
     * @brief enum representing the integer type of the item. It should
     * declare a Type value. UserType is the lowest permitted type value for
     * custom items (subclasses of QGraphicsItem or any of the standard items).
     * This value is used in conjunction with a reimplementation of
     * QGraphicsItem::type() and declaring a Type enum value.
     */
    enum { Type = UserType + 1 };

    /**
     * @brief line item constructor
     *
     * @param startItem the item at the left side of the line
     * @param endItem the item at the right side of the line
     * @param widget pointer to the parent widget of the line item
     */
    ArrowLineItem(
        const QGraphicsItem* startItem,
        const QGraphicsItem* endItem,
        QGraphicsItem* parent = 0
    );

    /**
     * @brief getter of the integer version of the type of the line item.
     * 
     * Used by Qt
     * 
     * @return int 
     */
    int type() const override;

    /**
     * @brief Qt method that gives the outer bounds of the line as a rectangle
     * 
     * @return QRectF 
     */
    QRectF boundingRect() const override;

    /**
     * @brief Qt method that defines the shape of the line as a QPainterPath
     * 
     * This method adds the two extra arrows to the basic line shape
     * 
     * @return QPainterPath 
     */
    QPainterPath shape() const override;

    /**
     * @brief update the color of the line
     * 
     * @param color color of the line
     */
    void setColor(const QColor &color);

    /**
     * @brief make appear or disappear the start item arrow head
     *
     * @param enabled boolean to enable or disable a start arrow head
     */
    void enableStartArrowHead(const bool &enabled);

    /**
    * @brief start QGraphicsItem item the line links
    *
    * @return QGraphicsItem *
    */
    const QGraphicsItem* startItem() const;

    /**
    * @brief end QGraphicsItem item the line links
    *
    * @return QGraphicsItem *
    */
    const QGraphicsItem* endItem() const;

    /**
     * @brief update the line position 
     * 
     * New position is set considering the current position of the two items to
     * link (m_startItem & m_endItem)
     */
    void updatePosition();

protected:
    /**
     * @brief Qt method that paints the contents of the line item.
     * 
     * @param painter pointer to the Qt painter of the line item 
     * @param option pointer to the Qt style options of the line item 
     * @param widget pointer to the parent widget of the line item 
     */
    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget = 0
    ) override;

private:
    struct Impl;
    const std::unique_ptr<Impl> m_impl;
};

#endif
