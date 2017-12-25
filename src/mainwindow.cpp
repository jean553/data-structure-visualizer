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
    QMenu* doubleLinkedListMenu;

    QAction* createLinkedListAction;
    QAction* insertAtTheEndLinkedListAction;
    QAction* insertAtTheBeginningLinkedListAction;
    QAction* insertAfterLinkedListAction;
    QAction* atLinkedListAction;
    QAction* dropAtLinkedListAction;

    QAction* createDoubleLinkedListAction;

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

    auto& createLinkedListAction = impl->createLinkedListAction;
    auto& insertAtTheEndLinkedListAction =
        impl->insertAtTheEndLinkedListAction;
    auto& insertAtTheBeginningLinkedListAction =
        impl->insertAtTheBeginningLinkedListAction;
    auto& insertAfterLinkedListAction = impl->insertAfterLinkedListAction;
    auto& atLinkedListAction = impl->atLinkedListAction;
    auto& dropAtLinkedListAction = impl->dropAtLinkedListAction;

    auto& createDoubleLinkedListAction = impl->createDoubleLinkedListAction;

    createLinkedListAction = new QAction("Create");
    connect(
        createLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(createLinkedList())
    );

    insertAtTheEndLinkedListAction = new QAction("Insert at the end");
    connect(
        insertAtTheEndLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAtTheEndLinkedList())
    );

    insertAtTheBeginningLinkedListAction = new QAction("Insert at the beginning");
    connect(
        insertAtTheBeginningLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAtTheBeginningLinkedList())
    );

    insertAfterLinkedListAction = new QAction("Insert after");
    connect(
        insertAfterLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAfterLinkedList())
    );

    atLinkedListAction = new QAction("At");
    connect(
        atLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(atLinkedList())
    );

    dropAtLinkedListAction = new QAction("Drop at");
    connect(
        dropAtLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(dropAtLinkedList())
    );

    createDoubleLinkedListAction = new QAction("Create");
    connect(
        createDoubleLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(createDoubleLinkedList())
    );

    auto& linkedListMenu = impl->linkedListMenu;
    linkedListMenu = menuBar()->addMenu("Linked list");
    linkedListMenu->addAction(createLinkedListAction);
    linkedListMenu->addAction(insertAtTheEndLinkedListAction);
    linkedListMenu->addAction(insertAtTheBeginningLinkedListAction);
    linkedListMenu->addAction(insertAfterLinkedListAction);
    linkedListMenu->addAction(atLinkedListAction);
    linkedListMenu->addAction(dropAtLinkedListAction);

    auto& doubleLinkedListMenu = impl->doubleLinkedListMenu;
    doubleLinkedListMenu = menuBar()->addMenu("Double linked list");
    doubleLinkedListMenu->addAction(createDoubleLinkedListAction);

    insertAtTheEndLinkedListAction->setEnabled(false);
    insertAtTheBeginningLinkedListAction->setEnabled(false);
    insertAfterLinkedListAction->setEnabled(false);
    atLinkedListAction->setEnabled(false);
    dropAtLinkedListAction->setEnabled(false);

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

    impl->createLinkedListAction->setEnabled(false);
    impl->insertAtTheEndLinkedListAction->setEnabled(true);
    impl->insertAtTheBeginningLinkedListAction->setEnabled(true);
    impl->insertAfterLinkedListAction->setEnabled(true);
    impl->atLinkedListAction->setEnabled(true);
    impl->dropAtLinkedListAction->setEnabled(true);

    impl->createDoubleLinkedListAction->setEnabled(false);
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

    auto ok = dialog->exec();
    if (ok == QDialog::Rejected)
    {
        return;
    }

    scene->insertAfterLinkedList(
        dialog->getIndex(),
        dialog->getData()
    );
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
        impl->createLinkedListAction->setEnabled(true);
        impl->insertAtTheEndLinkedListAction->setEnabled(false);
        impl->insertAtTheBeginningLinkedListAction->setEnabled(false);
        impl->insertAfterLinkedListAction->setEnabled(false);
        impl->atLinkedListAction->setEnabled(false);
        impl->dropAtLinkedListAction->setEnabled(false);
    }

    scene->dropAtIndexLinkedList(index);
}

/**
 *
 */
void MainWindow::createDoubleLinkedList()
{
    bool set {false};

    const int data = QInputDialog::getInt(
        this,
        "Double linked list",
        "Double linked list first node data:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        MAXIMUM_VALUE,
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    /* FIXME: call the library double linked list creation function */

    impl->createLinkedListAction->setEnabled(false);
    impl->createDoubleLinkedListAction->setEnabled(false);
}
