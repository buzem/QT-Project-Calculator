#include "calculatorwidget.h"
#include "calculatorcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CalculatorWidget *w = new CalculatorWidget();
    CalculatorController *controller = new CalculatorController(w);
    controller->start();

    return a.exec();
}
