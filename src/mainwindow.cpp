#include "mainwindow.hpp"
#include "scene.hpp"

#include <QMenuBar>
#include <QMenu>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QInputDialog>

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
        this,
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

/**
 *
 */
void MainWindow::createLinkedList()
{
    bool set {false};

    constexpr int DEFAULT_VALUE {0};
    constexpr int MINIMUM_VALUE {0};
    constexpr int MAXIMUM_VALUE {100};
    constexpr int STEP {1};
    const int data = QInputDialog::getInt(
        this,
        "Create linked list",
        "Linked list first node data:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        MAXIMUM_VALUE,
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    impl->scene->createLinkedList(data);
}
