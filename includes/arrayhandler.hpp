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
     * @brief allocate the array with the given size
     *
     * @param size the size of the array to allocate
     */
    void createArray(const int& size) const & noexcept;

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
