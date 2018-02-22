#ifndef HASHMAPHANDLER_H_
#define HASHMAPHANDLER_H_

#include "arrowlineitem.hpp"

#include <memory>

class HashmapHandler
{

public:

    /**
     * @brief hashmap handler constructor
     */
    HashmapHandler();

    /**
     * @brief default destructor
     */
    ~HashmapHandler();

    /**
     * @brief called from the hashmap menu create action;
     * creates a new hashmap
     *
     * @param the size of the hashmap to create
     */
    void createHashmap(const unsigned short& size); 

    /**
     * @brief get the graphical connector of two consecutive items of the map
     *
     * @param firstItem garphical item of the map
     * @param secondItem garphical item of the map right after firstItem
     * 
     * @return ArrowLineItem*
     */
    static ArrowLineItem* getConnectorFromItems(
        const QGraphicsItem* const firstItem,
        const QGraphicsItem* const secondItem
    );

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
