#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

#include <memory>

class MainWindow : public QMainWindow
{

public:

    /**
     * @brief main window constructor
     *
     * NOTE: QObject has neither a copy constructor nor an assignment operator.
     * http://doc.qt.io/qt-5/qobject.html#no-copy-constructor-or-assignment-operator
     */
    MainWindow();

    /**
     * @brief default destructor
     */
    ~MainWindow();

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
