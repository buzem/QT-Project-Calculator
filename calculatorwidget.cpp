#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPalette>
#include <QColor>
#include "calculatorcontroller.h"
#include "calculatorwidget.h"

#define MAX_SHOW_NUMBER_LENGTH 10 // display line edit only displays this number digits.

CalculatorWidget::CalculatorWidget(QWidget *parent) : QWidget(parent)
{
    this->createUI();
}

CalculatorWidget::~CalculatorWidget()
{

}

/**
 * @brief CalculatorWidget::setController
 * @param controller
 * Sets controller.
 */
void CalculatorWidget::setController(CalculatorController *controller) {
    this->controller = controller;
}

/**
 * @brief CalculatorWidget::createButton
 * @param text
 * @param action
 * Creates a button with a slot named action
 * which will be triggered when button clicked.
 */
QPushButton* CalculatorWidget::createButton(const QString &text, const char *action) {
    QPushButton *button = new QPushButton(text.toUpper());
    button->setFixedWidth(75);
    button->setFixedHeight(75);

    connect(button, SIGNAL(clicked()), this, action);
    return button;
}

/**
 * @brief CalculatorWidget::createDisplay
 * Creates two QLineEdits to display the result and operator.
 * Binds them to mainLayout.
 */
void CalculatorWidget::createDisplay() {
    QBoxLayout* displaysLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    displaysLayout->setSpacing(1);
    displaysLayout->setContentsMargins(0, 0, 0, 0);

    operatorDisplay = new QLineEdit("");

    operatorDisplay->setAlignment(Qt::AlignCenter);
    operatorDisplay->setReadOnly(true);
    operatorDisplay->setMaxLength(1);
    operatorDisplay->setFixedHeight(70);
    operatorDisplay->setFixedWidth(50);

    display = new QLineEdit("0");
    display->setAlignment(Qt::AlignRight);
    display->setReadOnly(true);
    display->setMaxLength(MAX_SHOW_NUMBER_LENGTH);
    display->setFixedHeight(70);

    QFont displayFont = display->font();
    displayFont.setPointSize(18);
    display->setFont(displayFont);
    operatorDisplay->setFont(displayFont);

    displaysLayout->addWidget(operatorDisplay);
    displaysLayout->addWidget(display);

    this->mainLayout->addLayout(displaysLayout);
}

/**
 * @brief CalculatorWidget::createUI
 * Creates displays, operator buttons and digit buttons.
 * Bind proper actions to them.
 */
void CalculatorWidget::createUI() {
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->setSpacing(1);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    QBoxLayout* operationsLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    operationsLayout->setSpacing(1);
    operationsLayout->setContentsMargins(0, 0, 0, 0);
    createDisplay();

    QPushButton* addButton = this->createButton("+", SLOT(onAddClickedWrapper()));
    operationsLayout->addWidget(addButton);

    QPushButton* subButton = this->createButton("-", SLOT(onSubClickedWrapper()));
    operationsLayout->addWidget(subButton);

    QPushButton* resButton = this->createButton("=", SLOT(onResClickedWrapper()));
    operationsLayout->addWidget(resButton);

    QPushButton* clearButton = this->createButton("CLR", SLOT(onClearClickedWrapper()));
    operationsLayout->addWidget(clearButton);
    operationsLayout->setSpacing(0);

    mainLayout->addLayout(operationsLayout);

    for(int i = 0; i < 4; i++) {
        QBoxLayout *tempLayout = new QBoxLayout(QBoxLayout::LeftToRight);
        tempLayout->setSpacing(1);
        tempLayout->setContentsMargins(0, 0, 0, 0);
        for(int j = 0; j < 4; j++) {
            QPushButton* digitButton = this->createButton(QString::number(i * 4 + j, 16), SLOT(onDigitClickedWrapper()));
            tempLayout->addWidget(digitButton);
        }
        mainLayout->addLayout(tempLayout);
    }

    setLayout(mainLayout);
}

/**
 * @brief CalculatorWidget::setDisplayText
 * @param text
 * Sets display's text.
 */
void CalculatorWidget::setDisplayText(QString text) {
    display->setText(text);
}

/**
 * @brief CalculatorWidget::setOperatorDisplayText
 * @param operatorDisplayText
 * Sets operatorDisplay's text.
 */
void CalculatorWidget::setOperatorDisplayText(QString operatorDisplayText) {
    operatorDisplay->setText(operatorDisplayText);
}

/**
 * @brief CalculatorWidget::onAddClickedWrapper
 * Wrapper slot for contoller's add action.
 */
void CalculatorWidget::onAddClickedWrapper() {
    controller->onAddClicked();
}

/**
 * @brief CalculatorWidget::onSubClickedWrapper
 * Wrapper slot for contoller's sub action.
 */
void CalculatorWidget::onSubClickedWrapper() {
    controller->onSubClicked();
}

/**
 * @brief CalculatorWidget::onSubClickedWrapper
 * Wrapper slot for contoller's res action.
 */
void CalculatorWidget::onResClickedWrapper() {
    controller->onResClicked();
}

/**
 * @brief CalculatorWidget::onSubClickedWrapper
 * Wrapper slot for contoller's clear action.
 */
void CalculatorWidget::onClearClickedWrapper() {
    controller->onClearClicked();
}

/**
 * @brief CalculatorWidget::onSubClickedWrapper
 * Wrapper slot for contoller's digit clicked action.
 */
void CalculatorWidget::onDigitClickedWrapper() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedDigit = clickedButton->text();
    controller->onDigitClicked(clickedDigit);
}

