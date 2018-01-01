#include "doublelinkedlisthandler.hpp"

#include "double_linked_list.h"

class DoubleLinkedListHandler::Impl
{

public:

    DoubleLinkedList list;
};

/**
 *
 */
DoubleLinkedListHandler::DoubleLinkedListHandler() :
    impl(std::make_unique<Impl>())
{
}

/**
 *
 */
DoubleLinkedListHandler::~DoubleLinkedListHandler() = default;

/**
 *
 */
void DoubleLinkedListHandler::createDoubleLinkedList(const int& data) const &
{
    impl->list = create(data);
}

/**
 *
 */
unsigned int DoubleLinkedListHandler::getSize() const &
{
    return size(&impl->list);
}

/**
 *
 */
unsigned int DoubleLinkedListHandler::getData(
    const unsigned int& index
) const &
{
    return at(
        &impl->list,
        index
    );
}
