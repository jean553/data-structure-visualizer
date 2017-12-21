#include "insertdialog.hpp"

#include <QLabel>
#include <QSpinBox>
#include <QGridLayout>
#include <QPushButton>

class InsertDialog::Impl
{

public:

    QGridLayout* layout;

    QLabel* indexLabel;
    QLabel* dataLabel;

    QSpinBox* indexLine;
    QSpinBox* dataLine;

    QPushButton* okButton;
    QPushButton* cancelButton;
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

    auto& okButton = impl->okButton;
    okButton = new QPushButton("OK", this);

    connect(
        okButton,
        SIGNAL(clicked()),
        this,
        SLOT(accept())
    );

    auto& cancelButton = impl->cancelButton;
    cancelButton = new QPushButton("Cancel", this);

    connect(
        cancelButton,
        SIGNAL(clicked()),
        this,
        SLOT(reject())
    );

    auto& layout = impl->layout;
    layout = new QGridLayout(this);

    /* write row integers directly as this is clearer for grid disposition */
    layout->addWidget(indexLabel, 0, 0, 1, 2);
    layout->addWidget(indexLine, 1, 0, 1, 2);
    layout->addWidget(dataLabel, 2, 0, 1, 2);
    layout->addWidget(dataLine, 3, 0, 1, 2);
    layout->addWidget(okButton, 4, 0, 1, 1);
    layout->addWidget(cancelButton, 4, 1, 1, 1);

    setLayout(layout);
}

/**
 *
 */
InsertDialog::~InsertDialog() = default;
