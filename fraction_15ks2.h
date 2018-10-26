/**
 * Author: Kyusung Shim
 * Student #: 10190942
 * CISC320 Assignment 2
 */
#pragma once

#ifndef FRACTION_LIBRARY_H
#define FRACTION_LIBRARY_H

#ifdef BUILDING_FRACTION_DLL
#define FRACTION_DLL __declspec(dllexport)
#else
#define FRACTION_DLL __declspec(dllimport)
#endif

#include <iostream>
#include <string>

using namespace std;

/**
 * Class representing a fraction.
 * A fraction is kept in its most simplified form
 * and a negative fraction is represented with a negative numerator.
 * All arithmetic operations and comparisons follow the properties of
 * real numbers.
 */
class FRACTION_DLL Fraction {
public:
    /**
     * Default constructor; is initialized as 0/1
     */
    Fraction();
    /**
     * Constructor for fractions in integer form
     */
    Fraction(const int numerator);
    /**
     * Constructor for fractions with a denominator where its absolute value is > 0
     */
    Fraction(int num, int den);

    /**
     * Accessor for a fraction's numerator
     */
    int numerator() const;
    /**
     * Accessor for a fraction's denominator
     */
    int denominator() const;

    Fraction operator-();
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator+=(const Fraction& right);

    /**
     * Input must be in this format: 2/5
     */
    friend istream& operator>>(istream& in, Fraction& value);

private:
    /**
     * Stores the numerator portion of the fraction
     */
    int num;
    /**
     * Stores the denominator portion of the fraction
     */
    int den;
    /**
     * Private function to help reduce a fraction to its simplest form
     * Finds the greatest common divisor between two numbers
     */
    static int getGCD(int n, int m);
};

/**
 * A fraction is represented as follows: 2/5
 */
ostream& FRACTION_DLL operator<<(ostream& out, const Fraction& value);
Fraction FRACTION_DLL operator+(const Fraction& left, const Fraction& right);
Fraction FRACTION_DLL operator-(const Fraction& left, const Fraction& right);
Fraction FRACTION_DLL operator*(const Fraction& left, const Fraction& right);
Fraction FRACTION_DLL operator/(const Fraction& left, const Fraction& right);
bool FRACTION_DLL operator==(const Fraction& left, const Fraction& right);
bool FRACTION_DLL operator!=(const Fraction& left, const Fraction& right);
bool FRACTION_DLL operator>(const Fraction& left, const Fraction& right);
bool FRACTION_DLL operator>=(const Fraction& left, const Fraction& right);
bool FRACTION_DLL operator<(const Fraction& left, const Fraction& right);
bool FRACTION_DLL operator<=(const Fraction& left, const Fraction& right);

/**
 * Error to throw when there is a 'bad' fraction.
 * Prominent example is when a denominator is 0.
 */
class FRACTION_DLL FractionException {
public:
    FractionException(const string& message);
    string& what();

private:
    string message;
};

#endif