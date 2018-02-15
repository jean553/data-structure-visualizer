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

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
