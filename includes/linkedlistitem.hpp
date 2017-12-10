#ifndef LINKEDLISTITEM_H_
#define LINKEDLISTITEM_H_

#include <QGraphicsTextItem>

#include <memory>

class LinkedListItem : public QGraphicsTextItem
{
    Q_OBJECT

public:

    /**
     * @brief default constructor
     *
     * @param data the data of the node
     */
    LinkedListItem(const int& data);

    /**
     * @brief default destructor
     */
    ~LinkedListItem();

    /**
     * @brief overrides the paint method that is called when item is displayed;
     * displays a border around the text and set background color
     *
     * @param painter painting implementation to modify
     * @param option painting options to modify
     * @param widget painted on widget (required by virtual function)
     */
    void paint(
        QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget
    );

private:

    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif
