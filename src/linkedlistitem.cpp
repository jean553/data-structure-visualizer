#include "linkedlistitem.hpp"

#include <QStyleOptionGraphicsItem>
#include <QPainter>

/**
 *
 */
class LinkedListItem::Impl
{

public:

    Impl(const int& data) : data(data)
    {
    }

    const int data;
};

/**
 *
 */
LinkedListItem::LinkedListItem(const int& data) :
    impl(std::make_unique<Impl>(data))
{
    setPlainText(QString::number(data));
}

/**
 *
 */
LinkedListItem::~LinkedListItem() = default;

/**
 *
 */
void LinkedListItem::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem* option,
    QWidget* widget
)
{
    constexpr int BACKGROUND_COLOR_RED {230};
    constexpr int BACKGROUND_COLOR_GREEN {230};
    constexpr int BACKGROUND_COLOR_BLUE {230};
    painter->setBrush(
        QColor(
            BACKGROUND_COLOR_RED,
            BACKGROUND_COLOR_GREEN,
            BACKGROUND_COLOR_BLUE
        )
    );
    painter->setPen(Qt::black);
    painter->drawRect(option->rect);

    /* sends the modified parameters to the paint() method
       that shoud have been called by the view */
    QGraphicsTextItem::paint(
        painter,
        option,
        widget
    );
}
