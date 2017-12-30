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
    void createDoubleLinkedList(const int& data) const &;

    /**
     * @brief getter of the double linked list size
     *
     * @return const unsigned int
     */
    const unsigned int getSize() const &;

    /**
     * @brief getter of the double linked list value at the given index
     *
     * @return const unsigned int
     */
    const unsigned int getData(const unsigned short& index) const &;

private:

    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif
