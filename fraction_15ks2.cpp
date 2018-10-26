/**
 * Author: Kyusung Shim
 * Student #: 10190942
 * CISC320 Assignment 2
 */
#include <iostream>
#include <string>

#include "fraction_15ks2.h"

using namespace std;

Fraction::Fraction() : num(0), den(1) {}
Fraction::Fraction(int numerator) : num(numerator), den(1) {}
Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw FractionException("Denominator cannot be 0");
    }
    if (numerator == 0) {
        num = 0;
        den = 1;
    } else {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int gcd = getGCD(abs(numerator), abs(denominator));

        num = numerator / gcd;
        den = denominator / gcd;
    }
}

int Fraction::numerator() const {
    return num;
}
int Fraction::denominator() const {
    return den;
}
int Fraction::getGCD(int n, int m) {
    int gcd;
    if (n >= m && n % m == 0) {
        gcd = m;
    } else if (n < m) {
        gcd = getGCD(m, n);
    } else {
        gcd = getGCD(m, n % m);
    }
    return gcd;
}

Fraction Fraction::operator-() {
    return Fraction(-num, den);
}
Fraction& Fraction::operator++() {
    num += den;
    return *this;
}
Fraction Fraction::operator++(int unused) {
    Fraction clone(num, den);
    num += den;
    return clone;
}
Fraction& Fraction::operator+=(const Fraction& right) {
    Fraction mediator(num, den); // allows + operator to be used
    mediator = mediator + right;
    num = mediator.numerator();
    den = mediator.denominator();
    return *this;
}

ostream& operator<<(ostream& out, const Fraction& value) {
    out << value.numerator() << '/' << value.denominator();
    return out;
}
istream& operator>>(istream& in, Fraction& value) {
    // NOTE: this operator does not handle cases where the input value is
    // not a proper fraction or an integer
    string numberStr;
    in >> numberStr;
    int numerator, denominator(1);
    size_t index;
    numerator = stoi(numberStr, &index);
    string slashAndDenominator(numberStr.substr(index));
    if (!slashAndDenominator.empty()) {
        denominator = stoi(slashAndDenominator.substr(1));
    }
    Fraction temp(numerator, denominator); // simplifies the fraction
    value.num = temp.numerator();
    value.den = temp.denominator();
    return in;
}
Fraction operator+(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator() * right.denominator() + right.numerator() * left.denominator(),
                    left.denominator() * right.denominator());
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator() * right.denominator() - right.numerator() * left.denominator(),
                    left.denominator() * right.denominator());
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator() * right.numerator(),
                    left.denominator() * right.denominator());
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator() * right.denominator(),
                    left.denominator() * right.numerator());
}
bool operator==(const Fraction& left, const Fraction& right) {
    return left.numerator() == right.numerator() &&
           left.denominator() == right.denominator();
}
bool operator!=(const Fraction& left, const Fraction& right) {
    return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right) {
    return left.numerator() * right.denominator() > right.numerator() * left.denominator();
}
bool operator>=(const Fraction& left, const Fraction& right) {
    return left > right || left == right;
}
bool operator<(const Fraction& left, const Fraction& right) {
    return !(left >= right);
}
bool operator<=(const Fraction& left, const Fraction& right) {
    return !(left > right);
}

FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() {
    return message;
}
