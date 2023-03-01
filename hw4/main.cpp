/*
 * Write a class implementation of complex numbers  including operators +,+=,- and -= and a length/absolute value function.
 * In addition, add multiplication and division operators. Provide the class header, class implementation and a test program with two complex
 * numbers illustrating the functionalities of your complex number class.
 */
#include <iostream>
#include "Complex.h"

int main(){

    using namespace std;

    Complex a(5,4);
    Complex b(5,6);

    cout << a.to_string() << " + " << b.to_string() << " = " << (a+b).to_string() << endl;
    cout << a.to_string() << " - " << b.to_string() << " = " << (a-b).to_string() << endl << endl;

    cout << a.to_string() << " += " << b.to_string() << " = ";
    a+=b;
    cout << a.to_string() << endl;

    cout << a.to_string() << " -= " << b.to_string() << " = ";
    a-=b;
    cout << a.to_string() << endl << endl;


    cout << a.to_string() << " * " << b.to_string() << " = " << (a*b).to_string() << endl;
    cout << a.to_string() << " / " << b.to_string() << " = " << (a/b).to_string() << endl << endl;

    cout << "Magnitude of " << a.to_string() << ": " << a.abs() << endl;
    cout << "Magnitude of " << b.to_string() << ": " << b.abs() << endl;

    return 0;
}