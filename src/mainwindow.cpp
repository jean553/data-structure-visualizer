#include "mainwindow.hpp"
#include "scene.hpp"

#include <QMenuBar>
#include <QMenu>
#include <QGraphicsView>
#include <QGraphicsTextItem>

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

    impl->scene = new Scene();
    impl->view = new QGraphicsView(impl->scene);

    impl->createAction = new QAction("Create");
    connect(
        impl->createAction,
        SIGNAL(triggered()),
        impl->scene,
        SLOT(createLinkedList())
    );

    impl->linkedListMenu = menuBar()->addMenu("Linked list");
    impl->linkedListMenu->addAction(impl->createAction);

    setCentralWidget(impl->view);
}

/**
 *
 */
MainWindow::~MainWindow() = default;
