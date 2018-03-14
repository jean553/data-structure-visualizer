#include "arrowlineitem.hpp"

#include <qmath.h>
#include <QPen>
#include <QPainter>


struct ArrowLineItem::Impl
{
    bool m_startArrowHeadEnabled;
    const QGraphicsItem *m_startItem;
    const QGraphicsItem *m_endItem;
    QColor m_color;
    QPolygonF m_endArrowHead;
    QPolygonF m_startArrowHead;
};


ArrowLineItem::ArrowLineItem(
    const QGraphicsItem *startItem,
    const QGraphicsItem *endItem,
    QGraphicsItem *parent
)
    : QGraphicsLineItem(parent),m_impl(std::make_unique<Impl>())
{
    m_impl->m_startItem = startItem;
    m_impl->m_endItem = endItem;
    m_impl->m_color = Qt::black;
    m_impl->m_startArrowHeadEnabled = false;
    setPen(QPen(m_impl->m_color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

/**
 *
 */
void ArrowLineItem::enableStartArrowHead(const bool &enabled)
{
    m_impl->m_startArrowHeadEnabled = enabled;
}

/**
 *
 */
void ArrowLineItem::setColor(const QColor &color)
{
    m_impl->m_color = color;
}

/**
 *
 */
const QGraphicsItem* ArrowLineItem::startItem() const
{
    return m_impl->m_startItem;
}

/**
 *
 */
const QGraphicsItem* ArrowLineItem::endItem() const
{
    return m_impl->m_endItem;
}

/**
 *
 */
int ArrowLineItem::type() const
{
    return Type;
}

/**
 *
 */
QRectF ArrowLineItem::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(
                line().p1(),
                QSizeF(
                    line().p2().x() - line().p1().x(),
                    line().p2().y() - line().p1().y()
                )
            )
            .normalized()
            .adjusted(-extra, -extra, extra, extra);
}

/**
 *
 */
QPainterPath ArrowLineItem::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(m_impl->m_startArrowHead);
    path.addPolygon(m_impl->m_endArrowHead);
    return path;
}

/**
 *
 */
void ArrowLineItem::updatePosition()
{
    QLineF line(
        mapFromItem(m_impl->m_startItem, 0, 0),
        mapFromItem(m_impl->m_endItem, 0, 0)
    );
    setLine(line);
}

/**
 *
 */
void ArrowLineItem::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem*,
    QWidget*
)
{
    if (m_impl->m_startItem->collidesWithItem(m_impl->m_endItem))
    {
        return;
    }

    QPen thisPen = pen();
    qreal arrowSize = 20;
    double arrowAngle(0);
    const QRectF startItemBounds = m_impl->m_startItem->boundingRect();

    thisPen.setColor(m_impl->m_color);
    painter->setPen(thisPen);
    painter->setBrush(m_impl->m_color);
    setLine(
        m_impl->m_startItem->x() + startItemBounds.width(),
        m_impl->m_startItem->y() + startItemBounds.height(),
        m_impl->m_endItem->x(),
        m_impl->m_endItem->y()
    );

    // Draw the line with no arrow
    painter->drawLine(line());

    arrowAngle = std::atan2(line().dy(), -line().dx());
    QPointF endArrowHeadLeftPoint = (
        line().p2() +
        QPointF(
            sin(arrowAngle + M_PI / 3) * arrowSize,
            cos(arrowAngle + M_PI / 3) * arrowSize
        )
    );
    QPointF endArrowHeadRightPoint = (
        line().p2() +
        QPointF(
            sin(arrowAngle + M_PI - M_PI / 3) * arrowSize,
            cos(arrowAngle + M_PI - M_PI / 3) * arrowSize
        )
    );

    m_impl->m_endArrowHead.clear();
    m_impl->m_endArrowHead << line().p2() << endArrowHeadLeftPoint 
                                  << endArrowHeadRightPoint;

    // Draw the end arrow (from left to right)
    painter->drawPolygon(m_impl->m_endArrowHead);

    if(m_impl->m_startArrowHeadEnabled)
    {
        arrowAngle = std::atan2(-line().dy(), line().dx());
        QPointF startArrowHeadLeftPoint = (
            line().p1() +
            QPointF(
                sin(arrowAngle + M_PI / 3) * arrowSize,
                cos(arrowAngle + M_PI / 3) * arrowSize
            )
        );
        QPointF startArrowHeadRightPoint = (
            line().p1() +
            QPointF(
                sin(arrowAngle + M_PI - M_PI / 3) * arrowSize,
                cos(arrowAngle + M_PI - M_PI / 3) * arrowSize
            )
        );
        m_impl->m_startArrowHead.clear();
        m_impl->m_startArrowHead << line().p1() << startArrowHeadLeftPoint
                                    << startArrowHeadRightPoint;

        // Draw the start arrow (from right to left)
        painter->drawPolygon(m_impl->m_startArrowHead);
    }
}
