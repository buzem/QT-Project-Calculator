#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QBoxLayout>
#include "calculatorcontroller.h"

class CalculatorController;

class CalculatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorWidget(QWidget *parent = 0);
    ~CalculatorWidget();
    QPushButton *createButton(const QString &text, const char *member);
    void setController(CalculatorController *controller);
    void setDisplayText(QString text);
    void setOperatorDisplayText(QString operatorDisplayText);

private slots:
    void onAddClickedWrapper();
    void onSubClickedWrapper();
    void onResClickedWrapper();
    void onClearClickedWrapper();
    void onDigitClickedWrapper();

private:
    CalculatorController *controller;
    QBoxLayout* mainLayout;
    QLineEdit* display;
    QLineEdit* operatorDisplay;

    void createUI();
    void createDisplay();
};

#endif // CALCULATORWIDGET_H
