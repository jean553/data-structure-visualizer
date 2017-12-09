#include "mainwindow.hpp"

#include <QMenuBar>
#include <QMenu>

class MainWindow::Impl {

public:

    QMenu* linkedListMenu;

    QAction* createAction;
};

/**
 *
 */
MainWindow::MainWindow() : impl(std::make_unique<Impl>())
{
    constexpr int WINDOW_WIDTH {800};
    constexpr int WINDOW_HEIGHT {600};
    setMinimumSize(
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );

    impl->createAction = new QAction("Create");

    impl->linkedListMenu = menuBar()->addMenu("Linked list");
    impl->linkedListMenu->addAction(impl->createAction);
}

/**
 *
 */
MainWindow::~MainWindow() = default;
