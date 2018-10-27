//
// Created by KYUSUNG on 25/10/2018.
//

#ifndef ASSIGNMENT3_CALCULATOR_H
#define ASSIGNMENT3_CALCULATOR_H

#include <QtWidgets>
#include "fractionGroup.h"

class Calculator : public QDialog {
    Q_OBJECT

public:
    Calculator();

private:
    void createOperations();
    void createEquals();

    void addClicked();
    void subtractClicked();
    void multiplyClicked();
    void divideClicked();

    FractionGroup *fractionOneBox;
    QGroupBox *operationsBox;
    FractionGroup *fractionTwoBox;
    QPushButton *equalsBtn;
    FractionGroup *resultBox;
};

#endif //ASSIGNMENT3_CALCULATOR_H
