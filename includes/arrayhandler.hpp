#ifndef ARRAYHANDLER_H_
#define ARRAYHANDLER_H_

#include "lineitem.hpp"

#include <memory>


class QGraphicsLineItem;

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

    /**
     * @brief get the graphical connector of two consecutive items of the array
     *
     * @param firstItem garphical item of the array
     * @param secondItem garphical item of the array right after firstItem
     * 
     * @returns LineItem*
     */
    static LineItem* getConnectorFromItems(
        const QGraphicsItem* const firstItem,
        const QGraphicsItem* const secondItem
    );

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
