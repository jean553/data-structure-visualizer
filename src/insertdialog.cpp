#include "insertdialog.hpp"

class InsertDialog::Impl
{

public:

    Impl()
    {
    }
};

/**
 *
 */
InsertDialog::InsertDialog() : impl(std::make_unique<Impl>())
{
}

/**
 *
 */
InsertDialog::~InsertDialog() = default;
