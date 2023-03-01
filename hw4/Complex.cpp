#include "Complex.h"

Complex::Complex() {
    re = 0;
    im = 0;
}

Complex::Complex(double r, double i) {
    re = r;
    im = i;
}

Complex Complex::operator+(const Complex &other) {
    return Complex(re + other.re, im + other.im);
}

Complex& Complex::operator+=(const Complex &other) {
    re += other.re;
    im += other.im;
    return *this;
}

Complex Complex::operator-(const Complex &other) {
    return Complex(re - other.re, im - other.im);
}

Complex& Complex::operator-=(const Complex &other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

Complex Complex::operator*(const Complex &other) {
    double real = re * other.re - im * other.im;
    double imaginary = re * other.im + im*other.re;
    return Complex(real, imaginary);
}

Complex Complex::operator/(const Complex &other) {

    double real = (re * other.re + im * other.im)/(other.re * other.re + other.im * other.im);
    double imaginary = (other.re*im - re * other.im)/(other.re * other.re + other.im * other.im);

    return Complex(real, imaginary);

}

std::string Complex::to_string() {
    return "(" + std::to_string(re) + ", " + std::to_string(im) + "i)";
}

double Complex::getReal(){return re;}
double Complex::getImaginary() {return im;}

double Complex::abs() {
    return sqrt(re*re + im*im);
}
