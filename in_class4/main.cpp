#include <iostream>
#include <cmath>

void to_cyl(const double &x, const double &y, double &r, double &phi);
void to_car(double &x, double &y, const double &r, const double &phi);

int main(){

    // Initial values
    double x, y, r, phi = 0;

    std::cout << "Provide value for x: ";
    std::cin >> x;
    std::cout << "Provide value for y: ";
    std::cin >> y;

    to_cyl(x, y, r, phi);

    std::cout << "X: " << x << " Y: " << y << std::endl;
    std::cout << "r: " << r << " phi: " << phi << std::endl;

    std::cout << "\nConverting back:\n";

    to_car(x, y, r, phi);
    std::cout << "X: " << x << " Y: " << y << std::endl;
    std::cout << "r: " << r << " phi: " << phi << std::endl;


    return 0;
}

void to_cyl(const double &x, const double &y, double &r, double &phi){
    r = sqrt( pow( x, 2 ) + pow(y, 2) );
    phi = atan2(y, x);
}
void to_car(double &x, double &y, const double &r, const double &phi){
    x = r * cos(phi);
    y = r * sin(phi);
}