#include "insertdialog.hpp"

#include <QLabel>
#include <QSpinBox>
#include <QGridLayout>

class InsertDialog::Impl
{

public:

    QGridLayout* layout;

    QLabel* indexLabel;
    QLabel* dataLabel;

    QSpinBox* indexLine;
    QSpinBox* dataLine;
};

/**
 *
 */
InsertDialog::InsertDialog(const int& maximumIndex) :
    impl(std::make_unique<Impl>())
{
    constexpr int WIDTH {200}; 
    constexpr int HEIGHT {160};
    setFixedSize(
        WIDTH,
        HEIGHT
    );

    setWindowTitle("Linked list");

    auto& indexLabel = impl->indexLabel;
    indexLabel = new QLabel("After index:", this);

    auto& dataLabel = impl->dataLabel;
    dataLabel = new QLabel("Data:", this);

    constexpr int MINIMUM_INDEX {0};
    auto& indexLine = impl->indexLine;
    indexLine = new QSpinBox(this);
    indexLine->setRange(
        MINIMUM_INDEX,
        maximumIndex
    );

    constexpr int MAXIMUM_DATA {99};
    constexpr int MINIMUM_DATA {0};
    auto& dataLine = impl->dataLine;
    dataLine = new QSpinBox(this);
    dataLine->setRange(
        MINIMUM_DATA,
        MAXIMUM_DATA
    );

    auto& layout = impl->layout;
    layout = new QGridLayout(this);
    layout->addWidget(indexLabel, 0, 0);
    layout->addWidget(indexLine, 1, 0);
    layout->addWidget(dataLabel, 2, 0);
    layout->addWidget(dataLine, 3, 0);

    setLayout(layout);
}

/**
 *
 */
InsertDialog::~InsertDialog() = default;
