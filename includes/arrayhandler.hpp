#ifndef ARRAYHANDLER_H_
#define ARRAYHANDLER_H_

#include <memory>

class ArrayHandler {

public:

    /**
     * @brief initializes the implementation
     */
    ArrayHandler();

    /**
     * @brief default destructor
     */
    ~ArrayHandler();

    /**
     * @brief allocates the array with the given size
     *
     * @param size the size of the array to allocate
     */
    void createArray(const std::size_t size) const & noexcept;

    /**
     * @brief free the allocated array
     */
    void dropArray() const & noexcept;

    /**
     * @brief returns the array current items amount
     *
     * @return std::size_t
     */
    std::size_t getAmount() const & noexcept;

    /**
     * @brief returns the array content at the given index
     *
     * @param index the index into the array
     *
     * @return int
     */
    int getData(const std::size_t index) const & noexcept;

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
