#include "arrayhandler.hpp"

class ArrayHandler::Impl {

public:

    int* array;
    std::size_t amount {0};
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
void ArrayHandler::createArray(const std::size_t size) const & noexcept
{
    auto& array = impl->array;
    array = static_cast<int*>(malloc(size * sizeof(int)));

    impl->amount = size;

    for (
        unsigned int index = 0;
        index < size;
        index += 1
    ) {
        array[index] = 0;
    }
}

/**
 *
 */
std::size_t ArrayHandler::getAmount() const & noexcept
{
    return impl->amount;
}

/**
 *
 */
int ArrayHandler::getData(const std::size_t index) const & noexcept
{
    return impl->array[index];
}
