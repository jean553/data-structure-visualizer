#include "lineitem.hpp"

/**
 *
 */
LineItem::LineItem()
{
    constexpr qreal LINE_LEFT_HORIZONTAL_POSITION {20.0};
    constexpr qreal LINE_LEFT_VERTICAL_POSITION {20.0};
    constexpr qreal LINE_RIGHT_HORIZONTAL_POSITION {60.0};
    constexpr qreal LINE_RIGHT_VERTICAL_POSITION {60.0};
    setLine(
        LINE_LEFT_HORIZONTAL_POSITION,
        LINE_LEFT_VERTICAL_POSITION,
        LINE_RIGHT_HORIZONTAL_POSITION,
        LINE_RIGHT_VERTICAL_POSITION
    );
}
