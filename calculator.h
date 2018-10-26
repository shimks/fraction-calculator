//
// Created by KYUSUNG on 25/10/2018.
//

#ifndef ASSIGNMENT3_CALCULATOR_H
#define ASSIGNMENT3_CALCULATOR_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>

class Calculator : public QDialog {
    Q_OBJECT

public:
    Calculator();

private:
    void createFractionBox(QGroupBox *fraction);
    void createOperations();
    void createEquals();

    void addClicked();
    void subtractClicked();
    void multiplyClicked();
    void divideClicked();

    QGroupBox *fractionOneBox;
    QGroupBox *operationsBox;
    QGroupBox *fractionTwoBox;
    QPushButton *equalsBtn;
    QGroupBox *resultBox;
};

#endif //ASSIGNMENT3_CALCULATOR_H
