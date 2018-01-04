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
