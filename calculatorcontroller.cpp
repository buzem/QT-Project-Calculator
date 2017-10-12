#include <QDebug>
#include "calculatorcontroller.h"
#include "calculatorwidget.h"

#define MAX_ACCEPT_NUMBER_LENGTH 6 // controller accepts max this number length number via digit clicks

CalculatorController::CalculatorController(CalculatorWidget* view) {
    this->view = view; // binds view to controller
    this->view->setController(this); // binds controller to view
    this->currentOperator = OPERATOR::NONE; // current operation is none
}

/**
 * @brief CalculatorController::start
 * Starts the controller, main thing to do is showing the view.
 */
void CalculatorController::start() {
    this->view->show();
}

/**
 * @brief CalculatorController::onAddClicked
 * If the current operator is none, takes currentText to memoryText and resets values.
 * If the current operator is not none and not res, makes the calculation.
 * After all, makes currentOperator add and tests operator display +.
 */
void CalculatorController::onAddClicked() {
    if (this->currentOperator != OPERATOR::NONE) {
        if(this->currentOperator != OPERATOR::RES) {
            this->calculateResult();
        }
    } else {
        this->memoryText = this->currentText;
        this->currentText = '0';
    }

    this->currentOperator = OPERATOR::ADD;
    this->view->setOperatorDisplayText("+");
}

/**
 * @brief CalculatorController::onSubClicked
 * If the current operator is none, takes currentText to memoryText and resets values.
 * If the current operator is not none and not res, makes the calculation.
 * After all, makes currentOperator sub and tests operator display +.
 */
void CalculatorController::onSubClicked() {
    if (this->currentOperator != OPERATOR::NONE) {
        if(this->currentOperator != OPERATOR::RES) {
            this->calculateResult();
        }
    } else {
        this->memoryText = this->currentText;
        this->currentText = '0';
    }

    this->currentOperator = OPERATOR::SUB;
    this->view->setOperatorDisplayText("-");
}

/**
 * @brief CalculatorController::onResClicked
 * If operator is not none, makes the calculation; changes operator to res.
 */
void CalculatorController::onResClicked() {
    if (this->currentOperator != OPERATOR::NONE) {
        this->calculateResult();
        this->currentOperator = OPERATOR::RES;
        this->view->setOperatorDisplayText("=");
    }
}

/**
 * @brief CalculatorController::onClearClicked
 * Resets to initial values.
 */
void CalculatorController::onClearClicked() {
    this->memoryText = QString::fromUtf8("0");
    this->currentText = QString::fromUtf8("0");
    this->currentOperator = OPERATOR::NONE;
    this->view->setDisplayText(currentText);
    this->view->setOperatorDisplayText("");
}

/**
 * @brief CalculatorController::onDigitClicked
 * @param clickedDigit
 * takes clickedDigit and changes the currentText to newly created number.
 * After, displays text.
 */
void CalculatorController::onDigitClicked(QString clickedDigit) {
    if (this->currentOperator == OPERATOR::RES) {
        this->currentOperator = OPERATOR::NONE;
        this->view->setOperatorDisplayText("");
    }

    if (this->currentText == "0") {
        this->currentText = clickedDigit;
    } else if (this->currentText.length() < MAX_ACCEPT_NUMBER_LENGTH){
        this->appendToCurrentText(clickedDigit);
    }

    this->view->setDisplayText(currentText);
}

/**
 * @brief CalculatorController::appendToCurrentText
 * @param appendText
 * Appends appendtext to currentText
 */
void CalculatorController::appendToCurrentText(QString appendText) {
    this->currentText = this->currentText.append(appendText);
}

/**
 * @brief CalculatorController::calculateResult
 * Calculates result.
 */
void CalculatorController::calculateResult() {
    bool okFirst, okSecond;
    int firstOperand = this->memoryText.toInt(&okFirst, 16);
    int secondOperand = this->currentText.toInt(&okSecond, 16);
    int result = 0;
    if (currentOperator == OPERATOR::ADD) {
        result = firstOperand + secondOperand;
    } else if(currentOperator == OPERATOR::SUB){
        result = firstOperand - secondOperand;
    }

    this->memoryText = this->QStringifyResult(result);
    this->currentText = QString::fromUtf8("0");
    this->view->setDisplayText(this->memoryText);
}

/**
 * @brief CalculatorController::QStringifyResult
 * @param result
 * @return QStringified result, takes 2's complement if the result is negative.
 */
QString CalculatorController::QStringifyResult(int result) {
    QString resultText;
    if (result >= 0) {
        resultText = QString::number(result, 16).toUpper();
    } else {
        resultText = QString::fromUtf8("-").append(QString::number(-result, 16).toUpper());
    }
    return resultText;
}
