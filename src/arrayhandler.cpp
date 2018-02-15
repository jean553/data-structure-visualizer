#include "arrayhandler.hpp"

class ArrayHandler::Impl {

public:

    int* array;
    unsigned int amount {0};
};

/**
 *
 */
ArrayHandler::ArrayHandler() : impl(std::make_unique<Impl>())
{
}

/**
 *
 */
ArrayHandler::~ArrayHandler() = default;

/**
 *
 */
void ArrayHandler::createArray(const unsigned int& size) const & noexcept
{
    impl->array = static_cast<int*>(malloc(size * sizeof(int)));

    impl->amount = size;
}
