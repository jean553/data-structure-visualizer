#include "arrayhandler.hpp"

class ArrayHandler::Impl {

public:

    int* array;
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
void ArrayHandler::createArray(const int& size) const & noexcept
{
    impl->array = static_cast<int*>(malloc(size * sizeof(int)));
}
