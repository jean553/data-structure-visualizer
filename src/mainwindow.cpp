#include "mainwindow.hpp"

#include <QMenuBar>
#include <QMenu>

class MainWindow::Impl {

public:

    QMenu* fileMenu;

    QAction* exitAction;
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

    impl->exitAction = new QAction("Exit");

    impl->fileMenu = menuBar()->addMenu("File");
    impl->fileMenu->addAction(impl->exitAction);
}

/**
 *
 */
MainWindow::~MainWindow() = default;
