#include "mainwindow.hpp"
#include "scene.hpp"

#include <QMenuBar>
#include <QMenu>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QInputDialog>

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

    auto& scene = impl->scene;
    auto& view = impl->view;

    scene = new Scene();

    /* set here in order to use the window dimensions */
    constexpr int WINDOW_ORIGINS {0};
    constexpr int SCENE_MARGINS {50};
    scene->setSceneRect(
        QRectF(
            WINDOW_ORIGINS,
            WINDOW_ORIGINS,
            WINDOW_WIDTH - SCENE_MARGINS,
            WINDOW_HEIGHT - SCENE_MARGINS
        )
    );

    view = new QGraphicsView(scene);

    auto& createAction = impl->createAction;
    auto& insertAtTheEndAction = impl->insertAtTheEndAction;
    auto& atAction = impl->atAction;

    createAction = new QAction("Create");
    connect(
        createAction,
        SIGNAL(triggered()),
        this,
        SLOT(createLinkedList())
    );

    insertAtTheEndAction = new QAction("Insert at the end");
    connect(
        insertAtTheEndAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAtTheEndLinkedList())
    );

    atAction = new QAction("At");
    connect(
        atAction,
        SIGNAL(triggered()),
        this,
        SLOT(atLinkedList())
    );

    auto& linkedListMenu = impl->linkedListMenu;
    linkedListMenu = menuBar()->addMenu("Linked list");
    linkedListMenu->addAction(createAction);
    linkedListMenu->addAction(insertAtTheEndAction);
    linkedListMenu->addAction(atAction);

    insertAtTheEndAction->setEnabled(false);
    atAction->setEnabled(false);

    setCentralWidget(view);
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

    auto& scene = impl->scene;

    const int index = QInputDialog::getInt(
        this,
        "Linked list",
        "Get data at index:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        scene->getLinkedListLastIndex(),
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    scene->selectItem(index);
}
