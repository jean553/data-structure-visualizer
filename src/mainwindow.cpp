#include "mainwindow.hpp"
#include "scene.hpp"

#include <QMenuBar>
#include <QMenu>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QInputDialog>

#include "linked_list.h"

constexpr int DEFAULT_VALUE {0};
constexpr int MINIMUM_VALUE {0};
constexpr int MAXIMUM_VALUE {100};
constexpr int STEP {1};

class MainWindow::Impl
{

public:

    QMenu* linkedListMenu;

    QAction* createAction;
    QAction* insertAtTheEndAction;
    QAction* atAction;

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

    /* set here in order to use the window dimensions;
       TODO: #18 should be optimized regarding the window dimensions */
    impl->scene->setSceneRect(
        QRectF(
            0,
            0,
            WINDOW_WIDTH,
            WINDOW_HEIGHT
        )
    );

    impl->view = new QGraphicsView(impl->scene);

    impl->createAction = new QAction("Create");
    connect(
        impl->createAction,
        SIGNAL(triggered()),
        this,
        SLOT(createLinkedList())
    );

    impl->insertAtTheEndAction = new QAction("Insert at the end");
    connect(
        impl->insertAtTheEndAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAtTheEndLinkedList())
    );

    impl->atAction = new QAction("At");
    connect(
        impl->atAction,
        SIGNAL(triggered()),
        this,
        SLOT(atLinkedList())
    );

    impl->linkedListMenu = menuBar()->addMenu("Linked list");
    impl->linkedListMenu->addAction(impl->createAction);
    impl->linkedListMenu->addAction(impl->insertAtTheEndAction);
    impl->linkedListMenu->addAction(impl->atAction);

    impl->insertAtTheEndAction->setEnabled(false);
    impl->atAction->setEnabled(false);

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

    const int data = QInputDialog::getInt(
        this,
        "Linked list",
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

    impl->insertAtTheEndAction->setEnabled(true);
    impl->atAction->setEnabled(true);
}

/**
 *
 */
void MainWindow::insertAtTheEndLinkedList()
{
    bool set {false};

    const int data = QInputDialog::getInt(
        this,
        "Linked list",
        "Last data to insert:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        MAXIMUM_VALUE,
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    impl->scene->insertAtTheEndLinkedList(data);
}

/**
 *
 */
void MainWindow::atLinkedList()
{
    bool set {false};

    const int index = QInputDialog::getInt(
        this,
        "Linked list",
        "Get data at index:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        impl->scene->getLinkedListLastIndex(),
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    impl->scene->selectItem(index);
}
