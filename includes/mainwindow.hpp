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

    /**
     * @brief called by the linked list menu insert at the beginning action;
     * displays the popup that asks for the starting linked list value
     *
     * not const as the dialog creation modifies the main window
     */
    void insertAtTheBeginningLinkedList();

    /**
     * @brief called by the linked list menu insert after action;
     * displays the popup that asks for the index after which one to insert
     *
     * not const as the dialog creation modifies the main window
     */
    void insertAfterLinkedList();

    /**
     * @brief called by the linked list menu at action;
     * displays the popup that asks for the linked list index
     *
     * not const as the dialog creation modifies the main window
     */
    void atLinkedList();

    /**
     * @brief called by the linked list menu drop at action;
     * displays the popup that asks for the linked list index
     *
     * not const as the dialog creation modifies the main window
     */
    void dropAtLinkedList();

    /**
     * @brief called by the linked list menu drop at the end action;
     * directly calls the handler function in order to drop at the end
     *
     * not const as the dialog creation modifies the main window
     */
    void dropAtTheEndLinkedList();

    /**
     * @brief called by the double linked list menu create action;
     * displays the popup that asks for the double linked list first value
     *
     * not const as the dialog creation modifies the main window
     */
    void createDoubleLinkedList();

    /**
     * @brief called by the double linked list menu insert at the end action;
     * displays the popup that asks for the double linked list value to insert
     *
     * not const as the dialog creation modifies the main window
     */
    void insertAtTheEndDoubleLinkedList();

    /**
     * @brief called by the double linked list menu insert at the beginning action;
     * displays the popup that asks for the double linked list value to insert
     *
     * not const as the dialog creation modifies the main window
     */
    void insertAtTheBeginningDoubleLinkedList();

    /**
     * @brief called by the double linked list menu drop at action;
     * displays the popup that asks for the double linked list node to remove
     *
     * not const as the dialog creation modifies the main window
     */
    void dropAtDoubleLinkedList();

    /**
     * @brief called by the array menu create action; displays the popup to specify the array size
     *
     * not const as the dialog creation modifies the main window
     */
    void createArray();

    /**
     * @brief called by the array menu drop action; removed the whole array
     *
     * not const as the dialog creation modifies the main window
     */
    void dropArray();

    /**
     * @brief called by the hashmap menu create action;
     *
     * TODO: to define
     */
    void createHashmap();

private:

    /**
     * @brief initializes the status of the menus options at their initial states;
     * refactored into one function as used at the construction of the window
     * but also when the current data structure is totally destroyed
     */
    void initializeMenusOptions();

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
