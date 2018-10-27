//
// Created by KYUSUNG on 25/10/2018.
//

#include <QtWidgets>
#include "calculator.h"
#include "fractionGroup.h"

Calculator::Calculator() {
    fractionOneBox = new FractionGroup;
    fractionTwoBox = new FractionGroup;
    resultBox = new FractionGroup;
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
