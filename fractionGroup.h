#include <QtWidgets>
#include <fraction_15ks2.h>

class FractionGroup : QGroupBox {
    Q_OBJECT
public:
    FractionGroup();
    Fraction getFraction();

private:
    QLineEdit *numeratorLine;
    QLineEdit *denominatorLine;
};