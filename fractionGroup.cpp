#include "fractionGroup.h"

FractionGroup::FractionGroup() {
    numeratorLine = new QLineEdit;
    denominatorLine = new QLineEdit;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(numeratorLine);
    layout->addWidget(denominatorLine);
    this->setLayout(layout);
}

Fraction FractionGroup::getFraction() {
    int numerator = numeratorLine->text().toInt();
    int denominator = denominatorLine->text().toInt();
    return Fraction(numerator, denominator);
}