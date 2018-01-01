#ifndef DOUBLELINKEDLISTHANDLER_H_
#define DOUBLELINKEDLISTHANDLER_H_

#include <memory>

class DoubleLinkedListHandler
{

public:

    /**
     * @brief double linked list handler constructor
     */
    DoubleLinkedListHandler();

    /**
     * @brief default destructor
     */
    ~DoubleLinkedListHandler();

    /**
     * @brief called from the double linked list menu create action;
     * create a new double linked list item
     *
     * @param data the data to insert into the first node
     */
    void createDoubleLinkedList(const int& data) const & noexcept;

    /**
     * @brief called from the double linked list menu insert at the end action;
     * add a new node to the double linked list at the end
     *
     * @param data the data to insert into the new node
     */
    void insertAtTheEndDoubleLinkedList(const int& data) const & noexcept;

    /**
     * @brief getter of the double linked list size
     *
     * @return unsigned int
     */
    unsigned int getSize() const & noexcept;

    /**
     * @brief getter of the double linked list value at the given index
     *
     * @return unsigned int
     */
    unsigned int getData(const unsigned int& index) const & noexcept;

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
