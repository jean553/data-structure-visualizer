#include "hashmaphandler.hpp"

#include "hashmap.h"

class HashmapHandler::Impl
{

public:

    Hashmap hashmap;
};

/**
 *
 */
HashmapHandler::HashmapHandler() :
    impl(std::make_unique<Impl>())
{
}

/**
 *
 */
HashmapHandler::~HashmapHandler() = default;

/**
 *
 */
void HashmapHandler::createHashmap(const unsigned short& size)
{
    impl->hashmap = createHM(size);
}

/**
 *
 */
ArrowLineItem* HashmapHandler::getConnectorFromItems(
    const QGraphicsItem* const firstItem,
    const QGraphicsItem* const secondItem
)
{
    return new ArrowLineItem(firstItem, secondItem);
}
