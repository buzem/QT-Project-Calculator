#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include <QString>
#include "calculatorwidget.h"

class CalculatorWidget;
enum OPERATOR { NONE, ADD, SUB, RES };

class CalculatorController {
public:
    CalculatorController(CalculatorWidget *view);
    CalculatorWidget *view;
    OPERATOR currentOperator;
    QString memoryText;
    QString currentText;
    void start();

public slots:
    void onAddClicked();
    void onSubClicked();
    void onResClicked();
    void onClearClicked();
    void onDigitClicked(QString clickedDigit);

private:
    void appendToCurrentText(QString appendText);
    void calculateResult();
    QString QStringifyResult(int result);
};

#endif // CALCULATORCONTROLLER_H
