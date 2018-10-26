//
// Created by KYUSUNG on 25/10/2018.
//

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include "calculator.h"

Calculator::Calculator() {
    createFractionBox(fractionOneBox);
//    createOperations();
//    createFractionBox(fractionTwoBox);
//    createEquals();
//    createFractionBox(resultBox);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(fractionOneBox);
//    layout->addWidget(operationsBox);
//    layout->addWidget(fractionTwoBox);
//    layout->addWidget(equalsBtn);
//    layout->addWidget(resultBox);
}

void Calculator::createFractionBox(QGroupBox *fraction) {
    fraction = new QGroupBox;
    QVBoxLayout *layout = new QVBoxLayout;
    QLineEdit *numerator = new QLineEdit;
    QFrame *fractionLine = new QFrame;
    QLineEdit *denominator = new QLineEdit;
}