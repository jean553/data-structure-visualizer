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
void DoubleLinkedListHandler::createDoubleLinkedList(const int& data) const & noexcept
{
    impl->list = create(data);
}

/**
 *
 */
void DoubleLinkedListHandler::insertAtTheEndDoubleLinkedList(const int& data)
    const & noexcept
{
    insertAtTheEnd(
        &impl->list,
        data
    );
}

/**
 *
 */
unsigned int DoubleLinkedListHandler::getSize() const & noexcept
{
    return size(&impl->list);
}

/**
 *
 */
unsigned int DoubleLinkedListHandler::getLastIndex() const & noexcept
{
    return size(&impl->list) - 1;
}

/**
 *
 */
unsigned int DoubleLinkedListHandler::getData(
    const unsigned int& index
) const & noexcept
{
    return at(
        &impl->list,
        index
    );
}
