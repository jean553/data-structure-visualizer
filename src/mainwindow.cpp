#include "mainwindow.hpp"
#include "scene.hpp"
#include "insertdialog.hpp"

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
    QAction* insertAtTheBeginningAction;
    QAction* insertAfterAction;
    QAction* atAction;
    QAction* dropAtAction;

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
    auto& insertAtTheBeginningAction = impl->insertAtTheBeginningAction;
    auto& insertAfterAction = impl->insertAfterAction;
    auto& atAction = impl->atAction;
    auto& dropAtAction = impl->dropAtAction;

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

    insertAtTheBeginningAction = new QAction("Insert at the beginning");
    connect(
        insertAtTheBeginningAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAtTheBeginningLinkedList())
    );

    insertAfterAction = new QAction("Insert after");
    connect(
        insertAfterAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAfterLinkedList())
    );

    atAction = new QAction("At");
    connect(
        atAction,
        SIGNAL(triggered()),
        this,
        SLOT(atLinkedList())
    );

    dropAtAction = new QAction("Drop at");
    connect(
        dropAtAction,
        SIGNAL(triggered()),
        this,
        SLOT(dropAtLinkedList())
    );

    auto& linkedListMenu = impl->linkedListMenu;
    linkedListMenu = menuBar()->addMenu("Linked list");
    linkedListMenu->addAction(createAction);
    linkedListMenu->addAction(insertAtTheEndAction);
    linkedListMenu->addAction(insertAtTheBeginningAction);
    linkedListMenu->addAction(insertAfterAction);
    linkedListMenu->addAction(atAction);
    linkedListMenu->addAction(dropAtAction);

    insertAtTheEndAction->setEnabled(false);
    insertAtTheBeginningAction->setEnabled(false);
    insertAfterAction->setEnabled(false);
    atAction->setEnabled(false);
    dropAtAction->setEnabled(false);

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

    impl->createAction->setEnabled(false);
    impl->insertAtTheEndAction->setEnabled(true);
    impl->insertAtTheBeginningAction->setEnabled(true);
    impl->insertAfterAction->setEnabled(true);
    impl->atAction->setEnabled(true);
    impl->dropAtAction->setEnabled(true);
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
void MainWindow::insertAtTheBeginningLinkedList()
{
    bool set {false};

    const int data = QInputDialog::getInt(
        this,
        "Linked list",
        "First data to insert:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        MAXIMUM_VALUE,
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    impl->scene->insertAtTheBeginningLinkedList(data);
}

/**
 *
 */
void MainWindow::insertAfterLinkedList()
{
    bool set {false};

    auto& scene = impl->scene;

    const auto maximumIndex = scene->getLinkedListLastIndex();
    InsertDialog* dialog = new InsertDialog(maximumIndex);
    dialog->show();
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

/**
 *
 */
void MainWindow::dropAtLinkedList()
{
    bool set {false};

    auto& scene = impl->scene;

    const int index = QInputDialog::getInt(
        this,
        "Linked list",
        "Drop at index:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        scene->getLinkedListLastIndex(),
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    if (scene->getLinkedListLastIndex() == 0)
    {
        impl->createAction->setEnabled(true);
        impl->insertAtTheEndAction->setEnabled(false);
        impl->insertAtTheBeginningAction->setEnabled(false);
        impl->atAction->setEnabled(false);
        impl->dropAtAction->setEnabled(false);
    }

    scene->dropAtIndexLinkedList(index);
}
