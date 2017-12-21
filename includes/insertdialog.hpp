#ifndef INSERTDIALOG_H_
#define INSERTDIALOG_H_

#include <QDialog>

#include <memory>

class InsertDialog : public QDialog
{
    Q_OBJECT
    
public:

    /**
     * @brief insert dialog constructor
     *
     * @param maximumIndex the maximum index allowed
     */
    InsertDialog(const int& maximumIndex);

    /**
     * @brief default destructor
     */
    ~InsertDialog();

private:

    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif
