#include <iostream>
#include <cmath>

// IC1
//void to_cyl(const double &x, const double &y, double &r, double &phi);
//void to_car(double &x, double &y, const double &r, const double &phi);
//
//int main(){
//
//    // Initial values
//    double x, y, r, phi = 0;
//
//    std::cout << "Provide value for x: ";
//    std::cin >> x;
//    std::cout << "Provide value for y: ";
//    std::cin >> y;
//
//    to_cyl(x, y, r, phi);
//
//    std::cout << "X: " << x << " Y: " << y << std::endl;
//    std::cout << "r: " << r << " phi: " << phi << std::endl;
//
//    std::cout << "\nConverting back:\n";
//
//    to_car(x, y, r, phi);
//    std::cout << "X: " << x << " Y: " << y << std::endl;
//    std::cout << "r: " << r << " phi: " << phi << std::endl;
//
//
//    return 0;
//}
//
//void to_cyl(const double &x, const double &y, double &r, double &phi){
//    r = sqrt( pow( x, 2 ) + pow(y, 2) );
//    phi = atan2(y, x);
//}
//void to_car(double &x, double &y, const double &r, const double &phi){
//    x = r * cos(phi);
//    y = r * sin(phi);
//}

////IC2=========================================================================================
//void add_vector(double* a, const double* b, int size){
//    //Will store the result in a.
//    for(int i = 0; i < size; i++){
//        a[i] += b[i];
//    }
//}
//
//void multiply_vector(double* a, const double* b, int size){
//    //Will store the result in a.
//    for(int i = 0; i < size; i++){
//        a[i] *= b[i];
//    }
//}
//
//void new_add_vector(const double* a, const double* b, double* c, int size){
//    //Will store the result in a.
//    for(int i = 0; i < size; i++){
//        c[i] = a[i] + b[i];
//    }
//}
//
//int main(){
//    const int size = 3;
//
//    double a[size] = {0, 1, 2};
//    double b[size] = {5, 6, 7};
//    double c[size];
//
//    add_vector(a, b, size);
//
//    std::cout << "Add a=a+b [ ";
//    for(int i = 0; i < size; i++){
//        std::cout << a[i] << " ";
//    }
//    std::cout << "].\n";
//
//    multiply_vector(a, b, size);
//
//    std::cout << "Multiply a=a*b[ ";
//    for(int i = 0; i < size; i++){
//        std::cout << a[i] << " ";
//    }
//    std::cout << "].\n";
//
//    new_add_vector(a, b, c, size);
//
//    std::cout << "Add c=a+b[ ";
//    for(int i = 0; i < size; i++){
//        std::cout << c[i] << " ";
//    }
//    std::cout << "].\n";
//
//    return 0;
//}

////IC3=========================================================================================
//
//void roll_results(const int* attempts_1, const int* attempts_2, int size){
//    std::cout << "===Results of rolls===\n";
//
//    std::cout << "Robot 1: [ ";
//    for(int i = 0; i < size; i++){
//        std::cout << attempts_1[i] << " ";
//    }
//    std::cout << "].\n";
//
//    std::cout << "Robot 2: [ ";
//    for(int i = 0; i < size; i++){
//        std::cout << attempts_2[i] << " ";
//    }
//    std::cout << "].\n";
//}
//
//void compare(const int* attempts_1, const int* attempts_2, int size){
//    int robot_1 = 0;
//    int robot_2 = 0;
//    int ties = 0;
//
//    for(int i = 0; i < size; i++){
//        if(attempts_1[i] > attempts_2[i]){
//            robot_1++;
//        }else if(attempts_1[i] < attempts_2[i]){
//            robot_2++;
//        }else{
//            ties++;
//        }
//    }
//
//    std::cout << "Robot 1 won " << robot_1 << " times.\n";
//    std::cout << "Robot 2 won " << robot_2 << " times.\n";
//    std::cout << "There were " << ties << " ties!\n";
//
//}
//
//int main(){
//
//    int size = 0;
//
//    std::cout << "How many times would you like the robots to roll the dice?:" << std::endl;
//    std::cin >> size;
//
//    int* attempts_1 = (int*)malloc(size * sizeof(int));
//    int* attempts_2 = (int*)malloc(size * sizeof(int));
//
//    //Random seed
//    std::srand(std::time(nullptr));
//
//    for (int i = 0; i < size; i++) {
//        attempts_1[i] = (std::rand() % 6) + 1;
//        attempts_2[i] = (std::rand() % 6) + 1;
//    }
//
//    roll_results(attempts_1, attempts_2, size);
//    std::cout << std::endl;
//    compare(attempts_1, attempts_2, size);
//
//    free(attempts_1);
//    free(attempts_2);
//}

//IC3+
#import <vector>

void roll_results(std::vector<int> &attempts_1, std::vector<int> &attempts_2){
    std::cout << "===Results of rolls===\n";

    std::cout << "Robot 1: [ ";
    for(int i = 0; i < attempts_1.size(); i++){
        std::cout << attempts_1[i] << " ";
    }
    std::cout << "].\n";

    std::cout << "Robot 2: [ ";
    for(int i = 0; i < attempts_2.size(); i++){
        std::cout << attempts_2[i] << " ";
    }
    std::cout << "].\n";
}

void compare(std::vector<int> &attempts_1, std::vector<int> &attempts_2){
    int robot_1 = 0;
    int robot_2 = 0;
    int ties = 0;

    for(int i = 0; i < attempts_1.size(); i++){
        if(attempts_1[i] > attempts_2[i]){
            robot_1++;
        }else if(attempts_1[i] < attempts_2[i]){
            robot_2++;
        }else{
            ties++;
        }
    }

    std::cout << "Robot 1 won " << robot_1 << " times.\n";
    std::cout << "Robot 2 won " << robot_2 << " times.\n";
    std::cout << "There were " << ties << " ties!\n";

}

int main(){

    int size = 0;

    std::cout << "How many times would you like the robots to roll the dice?:" << std::endl;
    std::cin >> size;

    std::vector<int> attempts_1;
    std::vector<int> attempts_2;

    //Random seed
    std::srand(std::time(nullptr));

    for (int i = 0; i < size; i++) {
        attempts_1.push_back((std::rand() % 6) + 1);
        attempts_2.push_back((std::rand() % 6) + 1);
    }

    roll_results(attempts_1, attempts_2);
    std::cout << std::endl;
    compare(attempts_1, attempts_2);
}