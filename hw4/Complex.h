#ifndef COMP_PHY_COMPLEX_H
#define COMP_PHY_COMPLEX_H

#include <string>
#include <math.h>

class Complex {
private:
    double re;
    double im;
public:
    // If no argument, the number will be represented be 0.
    Complex();
    Complex(double r, double i);

    Complex operator+(const Complex& other);
    Complex& operator+=(const Complex& other);
    Complex operator-(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex operator*(const Complex& other);
    Complex operator/(const Complex& other);

    double getReal();
    double getImaginary();
    double abs();
    std::string to_string();
};


#endif //COMP_PHY_COMPLEX_H
