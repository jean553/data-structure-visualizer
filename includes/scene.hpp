#ifndef SCENE_H_
#define SCENE_H_

#include <QGraphicsScene>

#include <memory>

struct LinkedList;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:

    /**
     * @brief scene constructor
     */
    Scene();

    /**
     * @brief default destructor
     */
    ~Scene();

    /**
     * @brief called from the linked list menu creation action;
     * it clears the whole scene content and add a new item
     *
     * @param data the data to insert into the first node
     *
     * not const as adding an item to the scene modifies it
     */
    void createLinkedList(const int& data) &;

    /**
     * @brief called from the linked list menu end insertion action;
     * it creates a new linked list node to the end of the existing list
     *
     * @param data the data to insert into the first node
     *
     * not const as adding an item to the scene modifies it
     */
    void insertAtTheEndLinkedList(const int& data) &;

    /**
     * @brief called from the linked list index popup
     *
     * @return const unsigned int
     */
    const unsigned int getLinkedListLastIndex() const &;

    /**
     * @brief highlight one item at the given index in red color
     *
     * @param index the index of the item to highlight
     */
    void selectItem(const int& index) &;

private:

    /**
     * @brief clears the scene and updates it according to the linked list;
     * creates the required items and prints them on the scene
     */
    void render() &;

    /**
     * @brief called everytime an item is added to the scene;
     * use the current position as the item position
     *
     * @param item the item with its position to be set
     */
    void applyCurrentItemPosition(QGraphicsTextItem* item) const &;

    /**
     * @brief called everytime an item is added to the scene;
     * increases the position of the currently inserted item
     */
    void increaseItemPositions() const & noexcept;

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
