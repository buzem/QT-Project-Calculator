/********************************************************************************
** Form generated from reading UI file 'calculatorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORWIDGET_H
#define UI_CALCULATORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorWidget
{
public:

    void setupUi(QWidget *CalculatorWidget)
    {
        if (CalculatorWidget->objectName().isEmpty())
            CalculatorWidget->setObjectName(QStringLiteral("CalculatorWidget"));
        CalculatorWidget->resize(400, 300);

        retranslateUi(CalculatorWidget);

        QMetaObject::connectSlotsByName(CalculatorWidget);
    } // setupUi

    void retranslateUi(QWidget *CalculatorWidget)
    {
        CalculatorWidget->setWindowTitle(QApplication::translate("CalculatorWidget", "CalculatorWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalculatorWidget: public Ui_CalculatorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORWIDGET_H
