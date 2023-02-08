#include <iostream>
#include <cmath>
/*
 * Problem: Implement a numerical differentiation using the secant method with fixed, but variable (user input) stepsize.
 * Calculate at 0,pi/4,pi/2, 3/4pi and pi the differntial of sin(x) and compare your results to the analytical expectation.
 */

const double pi = 3.1415926535;

//Template function that can evaluate a mathematical function
//Not strictly needed in this case, but I wanted to try it out.
template <typename F>
double difference_quotient(F f, double x, double epsilon){
    return (f( x + epsilon ) - f( x )) / epsilon;
}

namespace local {
    //Detours, sin and cos are overloads and would require a wierd cast (double*)(double)&std::sin
    double sin(double x) {
        return std::sin(x);
    }

    double cos(double x) {
        return std::cos(x);
    }
}


int main() {
    std::cout << "Please enter precision: ";

    double epsilon;
    std::cin >> epsilon;

    double sin0_analytical = local::cos(0);
    double sin0_numerical = difference_quotient(local::sin, 0, epsilon);
    std::cout << "(analytical) d/dx of sin(x) @ 0: " << sin0_analytical << std::endl;
    std::cout << "(numerical) d/dx of sin(x) @ 0 with epsilon " << epsilon << ": " << sin0_numerical << std::endl << std::endl;

    double sin1_analytical = local::cos(pi/4.0);
    double sin1_numerical = difference_quotient(local::sin, pi/4.0, epsilon);
    std::cout << "(analytical) d/dx of sin(x) @ pi/4: " << sin1_analytical << std::endl;
    std::cout << "(numerical) d/dx of sin(x) @ pi/4 with epsilon " << epsilon << ": " << sin1_numerical << std::endl << std::endl;

    double sin2_analytical = local::cos(pi/2.0);
    double sin2_numerical = difference_quotient(local::sin, pi/2.0, epsilon);
    std::cout << "(analytical) d/dx of sin(x) @ pi/2: " << sin2_analytical << std::endl;
    std::cout << "(numerical) d/dx of sin(x) @ pi/2 with epsilon " << epsilon << ": " << sin2_numerical << std::endl << std::endl;

    double sin3_analytical = local::cos(3.0*pi/4.0);
    double sin3_numerical = difference_quotient(local::sin, 3.0*pi/4.0, epsilon);
    std::cout << "(analytical) d/dx of sin(x) @ 3pi/4: " << sin3_analytical << std::endl;
    std::cout << "(numerical) d/dx of sin(x) @ 3pi/4 with epsilon " << epsilon << ": " << sin3_numerical << std::endl << std::endl;

    return 0;
}
