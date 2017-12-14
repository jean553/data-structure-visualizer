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
     * @brief called by the linked list menu create action;
     * displays the popup that asks for the linked list first value
     *
     * not const as the dialog creation modifies the main window
     */
    void createLinkedList();

    /**
     * @brief called by the linked list menu insert at the end action;
     * displays the popup that asks for the next linked list value
     *
     * not const as the dialog creation modifies the main window
     */
    void insertAtTheEndLinkedList();

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
