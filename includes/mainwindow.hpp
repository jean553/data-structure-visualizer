#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

class MainWindow : public QMainWindow
{

public:

    /**
     * @brief main window constructor
     */
    MainWindow();

    MainWindow(const MainWindow&) = delete;

    MainWindow operator=(const MainWindow&) = delete;
};

#endif
