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
