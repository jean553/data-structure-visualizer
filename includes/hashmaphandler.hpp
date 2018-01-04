#ifndef HASHMAPHANDLER_H_
#define HASHMAPHANDLER_H_

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

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
