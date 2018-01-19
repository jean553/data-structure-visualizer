#include "mainwindow.hpp"
#include "insertdialog.hpp"
#include "renderer.hpp"

#include "linkedlisthandler.hpp"
#include "doublelinkedlisthandler.hpp"
#include "hashmaphandler.hpp"

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
    QMenu* hashmapMenu;

    QAction* createLinkedListAction;
    QAction* insertAtTheEndLinkedListAction;
    QAction* insertAtTheBeginningLinkedListAction;
    QAction* insertAfterLinkedListAction;
    QAction* atLinkedListAction;
    QAction* dropAtLinkedListAction;

    QAction* createDoubleLinkedListAction;
    QAction* insertAtTheEndDoubleLinkedListAction;
    QAction* dropAtDoubleLinkedListAction;

    QAction* createHashmapAction;

    QGraphicsView* view;
    QGraphicsScene* scene;

    LinkedListHandler linkedListHandler;
    DoubleLinkedListHandler doubleLinkedListHandler;
    HashmapHandler hashmapHandler;
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

    auto& view = impl->view;
    auto& scene = impl->scene;

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

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

    auto& createLinkedListAction = impl->createLinkedListAction;
    auto& insertAtTheEndLinkedListAction =
        impl->insertAtTheEndLinkedListAction;
    auto& insertAtTheBeginningLinkedListAction =
        impl->insertAtTheBeginningLinkedListAction;
    auto& insertAfterLinkedListAction = impl->insertAfterLinkedListAction;
    auto& atLinkedListAction = impl->atLinkedListAction;
    auto& dropAtLinkedListAction = impl->dropAtLinkedListAction;

    auto& createDoubleLinkedListAction = impl->createDoubleLinkedListAction;
    auto& insertAtTheEndDoubleLinkedListAction =
        impl->insertAtTheEndDoubleLinkedListAction;
    auto& dropAtDoubleLinkedListAction = impl->dropAtDoubleLinkedListAction;

    auto& createHashmapAction = impl->createHashmapAction;

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

    insertAtTheEndDoubleLinkedListAction = new QAction("Insert at the end");
    connect(
        insertAtTheEndDoubleLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(insertAtTheEndDoubleLinkedList())
    );

    dropAtDoubleLinkedListAction = new QAction("Drop at");
    connect(
        dropAtDoubleLinkedListAction,
        SIGNAL(triggered()),
        this,
        SLOT(dropAtDoubleLinkedList())
    );

    createHashmapAction = new QAction("Create");
    connect(
        createHashmapAction,
        SIGNAL(triggered()),
        this,
        SLOT(createHashmap())
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
    doubleLinkedListMenu->addAction(insertAtTheEndDoubleLinkedListAction);
    doubleLinkedListMenu->addAction(dropAtDoubleLinkedListAction);

    auto& hashmapMenu = impl->hashmapMenu;
    hashmapMenu = menuBar()->addMenu("Hashmap");
    hashmapMenu->addAction(createHashmapAction);

    initializeMenusOptions();

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

    auto& linkedListHandler = impl->linkedListHandler;
    linkedListHandler.createLinkedList(data);
    ::render(
        impl->scene,
        &linkedListHandler
    );

    impl->createLinkedListAction->setEnabled(false);
    impl->createDoubleLinkedListAction->setEnabled(false);

    impl->insertAtTheEndLinkedListAction->setEnabled(true);
    impl->insertAtTheBeginningLinkedListAction->setEnabled(true);
    impl->insertAfterLinkedListAction->setEnabled(true);
    impl->atLinkedListAction->setEnabled(true);
    impl->dropAtLinkedListAction->setEnabled(true);
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

    auto& linkedListHandler = impl->linkedListHandler;
    linkedListHandler.insertAtTheEndLinkedList(data);
    ::render(
        impl->scene,
        &linkedListHandler
    );
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

    auto& linkedListHandler = impl->linkedListHandler;
    linkedListHandler.insertAtTheBeginningLinkedList(data);
    ::render(
        impl->scene,
        &linkedListHandler
    );
}

/**
 *
 */
void MainWindow::insertAfterLinkedList()
{
    auto& linkedListHandler = impl->linkedListHandler;

    const auto maximumIndex = linkedListHandler.getLinkedListLastIndex();
    InsertDialog* dialog = new InsertDialog(maximumIndex);

    auto ok = dialog->exec();
    if (ok == QDialog::Rejected)
    {
        return;
    }

    linkedListHandler.insertAfterLinkedList(
        dialog->getIndex(),
        dialog->getData()
    );
    ::render(
        impl->scene,
        &linkedListHandler
    );
}

/**
 *
 */
void MainWindow::atLinkedList()
{
    bool set {false};

    auto& linkedListHandler = impl->linkedListHandler;

    const int index = QInputDialog::getInt(
        this,
        "Linked list",
        "Get data at index:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        linkedListHandler.getLinkedListLastIndex(),
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    auto& scene = impl->scene;
    linkedListHandler.selectItem(
        scene,
        index
    );
    ::render(
        scene,
        &linkedListHandler
    );
}

/**
 *
 */
void MainWindow::dropAtLinkedList()
{
    bool set {false};

    auto& linkedListHandler = impl->linkedListHandler;

    const int index = QInputDialog::getInt(
        this,
        "Linked list",
        "Drop at index:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        linkedListHandler.getLinkedListLastIndex(),
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    linkedListHandler.dropAtIndexLinkedList(index);
    ::render(
        impl->scene,
        &linkedListHandler
    );

    if (linkedListHandler.getSize() == 0)
    {
        initializeMenusOptions();
    }
}

/**
 *
 */
void MainWindow::dropAtTheEndLinkedList()
{
    /* TODO */
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

    auto& doubleLinkedListHandler = impl->doubleLinkedListHandler;
    doubleLinkedListHandler.createDoubleLinkedList(data);
    ::render(
        impl->scene,
        &doubleLinkedListHandler
    );

    impl->createLinkedListAction->setEnabled(false);
    impl->createDoubleLinkedListAction->setEnabled(false);

    impl->insertAtTheEndDoubleLinkedListAction->setEnabled(true);
    impl->dropAtDoubleLinkedListAction->setEnabled(true);
}

/**
 *
 */
void MainWindow::insertAtTheEndDoubleLinkedList()
{
    bool set {false};

    const int data = QInputDialog::getInt(
        this,
        "Double linked list",
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

    auto& doubleLinkedListHandler = impl->doubleLinkedListHandler;
    doubleLinkedListHandler.insertAtTheEndDoubleLinkedList(data);
    ::render(
        impl->scene,
        &doubleLinkedListHandler
    );
}

/**
 *
 */
void MainWindow::createHashmap()
{
    bool set {false};

    const int size = QInputDialog::getInt(
        this,
        "Hashmap",
        "Size of the hashmap:",
        DEFAULT_VALUE,
        MINIMUM_VALUE,
        MAXIMUM_VALUE,
        STEP,
        &set
    );

    if (!set) {
        return;
    }

    auto& hashmapHandler = impl->hashmapHandler;
    hashmapHandler.createHashmap(size);

    /* TODO: rendering */
}

/**
 *
 */
void MainWindow::initializeMenusOptions()
{
    impl->createLinkedListAction->setEnabled(true);
    impl->createDoubleLinkedListAction->setEnabled(true);

    impl->insertAtTheEndLinkedListAction->setEnabled(false);
    impl->insertAtTheBeginningLinkedListAction->setEnabled(false);
    impl->insertAfterLinkedListAction->setEnabled(false);
    impl->atLinkedListAction->setEnabled(false);
    impl->dropAtLinkedListAction->setEnabled(false);
    impl->insertAtTheEndDoubleLinkedListAction->setEnabled(false);
    impl->dropAtDoubleLinkedListAction->setEnabled(false);
}
