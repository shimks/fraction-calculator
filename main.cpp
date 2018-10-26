#include <iostream>
#include <QtWidgets/QApplication>

#include "fraction_15ks2.h"
#include "calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.show();

    return app.exec();
}