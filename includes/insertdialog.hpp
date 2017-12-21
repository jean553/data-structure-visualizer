#ifndef INSERTDIALOG_H_
#define INSERTDIALOG_H_

#include <QDialog>

#include <memory>

class InsertDialog : public QDialog
{
    
public:

    /**
     * @brief insert dialog constructor
     */
    InsertDialog();

    /**
     * @brief default destructor
     */
    ~InsertDialog();

private:

    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif
