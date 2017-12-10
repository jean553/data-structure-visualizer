#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

#include <memory>

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

private slots:

    /**
     * @brief calls when the linked list menu create action is clicked
     */
    void createLinkedList();

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
