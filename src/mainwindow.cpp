#include "mainwindow.hpp"
#include "scene.hpp"

#include <QMenuBar>
#include <QMenu>
#include <QGraphicsView>

class MainWindow::Impl
{

public:

    QMenu* linkedListMenu;

    QAction* createAction;

    QGraphicsView* view;

    Scene* scene;
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

    impl->scene = new Scene();

    impl->view = new QGraphicsView(impl->scene);

    setCentralWidget(impl->view);
}

/**
 *
 */
MainWindow::~MainWindow() = default;
