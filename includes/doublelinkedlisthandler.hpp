#ifndef DOUBLELINKEDLISTHANDLER_H_
#define DOUBLELINKEDLISTHANDLER_H_

class DoubleLinkedListHandler
{

public:

    /**
     * @brief double linked list handler constructor
     */
    DoubleLinkedListHandler();

    /**
     * @brief called from the double linked list menu create action;
     * create a new double linked list item
     *
     * @param data the data to insert into the first node
     *
     * TODO: should be moved into a double linked list scene
     */
    void createDoubleLinkedList(const int& data) const &;
};

#endif
