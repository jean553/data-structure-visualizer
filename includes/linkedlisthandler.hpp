#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <memory>

struct LinkedList;
class QGraphicsScene;

class LinkedListHandler
{

public:

    /**
     * @brief scene constructor
     */
    LinkedListHandler();

    /**
     * @brief default destructor
     */
    ~LinkedListHandler();

    /**
     * @brief called from the linked list menu creation action;
     * it clears the whole scene content and add a new item
     *
     * @param data the data to insert into the first node
     */
    void createLinkedList(const int& data) const & noexcept;

    /**
     * @brief called from the linked list menu end insertion action;
     * it creates a new linked list node to the end of the existing list
     *
     * @param data the data to insert into the last node
     */
    void insertAtTheEndLinkedList(const int& data) const & noexcept;

    /**
     * @brief called from the linked list menu end insertion action;
     * it creates a new linked list node at the beginning of the existing list
     *
     * @param data the data to insert into the first node
     */
    void insertAtTheBeginningLinkedList(const int& data) const & noexcept;

    /**
     * @brief called from the linked list menu drop at action;
     * it removes the linked list item at the given index
     *
     * @param index the index of the node to remove
     */
    void dropAtIndexLinkedList(const int& index) const & noexcept;

    /**
     * @brief called from the linked list menu insert after action
     * it inserts the given data (node) after the given index
     *
     * @param index specifies after which index the new node must be inserted
     * @param data the data to insert into the new node
     */
    void insertAfterLinkedList(
        const int& index,
        const int& data
    ) const & noexcept;

    /**
     * @brief called from the linked list index popup
     *
     * @return unsigned int
     */
    unsigned int getLinkedListLastIndex() const & noexcept;

    /**
     * @brief highlight one item at the given index in red color
     *
     * @param index the index of the item to highlight
     *
     * not noexcept has the Qt called functions are not noexcept
     *
     * TODO: #48 after refactoring, this feature does not work anymore,
     * nothing happens; I should investigate why...
     */
    void selectItem(
        const QGraphicsScene* scene,
        const int& index
    ) const &;

    /**
     * @brief getter of the linked list size
     *
     * @return unsigned int
     */
    unsigned int getSize() const & noexcept;

    /**
     * @brief getter of the linked list value at the given index
     *
     * @return unsigned int
     */
    unsigned int getData(const unsigned short& index) const & noexcept;

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
