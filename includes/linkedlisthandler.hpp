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
     * @param data the data to insert into the last node
     *
     * not const as adding an item to the scene modifies it
     */
    void insertAtTheEndLinkedList(const int& data) &;

    /**
     * @brief called from the linked list menu end insertion action;
     * it creates a new linked list node at the beginning of the existing list
     *
     * @param data the data to insert into the first node
     *
     * not const as adding an item to the scene modifies it
     */
    void insertAtTheBeginningLinkedList(const int& data) &;

    /**
     * @brief called from the linked list menu drop at action;
     * it removes the linked list item at the given index
     *
     * @param index the index of the node to remove
     *
     * not const as adding an item to the scene modifies it
     */
    void dropAtIndexLinkedList(const int& index) &;

    /**
     * @brief called from the linked list menu insert after action
     * it inserts the given data (node) after the given index
     *
     * @param index specifies after which index the new node must be inserted
     * @param data the data to insert into the new node
     *
     * not const as adding an item to the scene modifies it
     */
    void insertAfterLinkedList(
        const int& index,
        const int& data
    ) &;

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

    /**
     * @brief called from the double linked list menu create action;
     * create a new double linked list item
     *
     * @param data the data to insert into the first node
     *
     * TODO: should be moved into a double linked list scene
     */
    void createDoubleLinkedList(const int& data) const &;

private:

    /**
     * @brief clears the scene and updates it according to the linked list;
     * creates the required items and prints them on the scene
     */
    void render() &;

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
