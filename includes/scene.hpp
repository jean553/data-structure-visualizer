#ifndef SCENE_H_
#define SCENE_H_

#include <QGraphicsScene>

#include <memory>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:

    /**
     * @brief scene constructor
     */
    Scene();

    /**
     * @brief default destructor
     */
    ~Scene();

    /**
     * @brief called from the linked list menu creation action;
     * it creates a new linked list node on the scene
     *
     * @param data the data to insert into the first node
     */
    void createLinkedList(const int& data);

    /**
     * @brief called from the linked list menu end insertion action;
     * it creates a new linked list node to the end of the existing list
     *
     * @param data the data to insert into the first node
     */
    void insertAtTheEndLinkedList(const int& data);

private:

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
