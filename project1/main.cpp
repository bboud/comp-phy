#include <iostream>
#include <fstream>
#include <math.h>

/*
 * Write a "simple" retirement calculator, which uses as an input the current, age you want to retire, current starting amount of money, current salary and the percentage
 * you wanna save and as a first step the assumed annual return of your investment (historically 5-6% is a reasonable starting point).
 * The program should print on the terminal (and in a text file) the input variables and the amount of money per year split out in your contributions vs the compounded interest part.
 */

int main(){
    using namespace std;
    //Input variables
    int c_age, r_age;
    double principal, c_salary, percent_to_save;

    // Input
    cout << "What is your current age?: " << endl;
    cin >> c_age;
    cout << endl << "What is you goal retirement age?: " << endl;
    cin >> r_age;
    cout << endl << "What is the amount of money you are starting with?: " << endl;
    cin >> principal;
    cout << endl << "What is your current salary?: " << endl;
    cin >> c_salary;
    cout << endl << "What percentage do you want to save?: " << endl;
    cin >> percent_to_save;

    float rate = percent_to_save/100.0;
    // Formula: A = P(1+r/n)^(nt)
    double c_interest = principal * pow(  ( 1 + rate ), ( r_age - c_age ) );

    // Output
    cout << "Current age: " << c_age << endl;
    cout << "Retirement age: " << r_age << endl;

    cout << "Principal: " << principal << endl;
    cout << "Current Salary: " << c_salary << endl;
    cout << "Percentage to save: " << percent_to_save << endl << endl;

    cout << "Yearly contributing amount: " << (c_salary*percent_to_save)/(r_age-c_age) << endl;
    cout << "Yearly compounded interest: " << c_interest / (r_age - c_age);

    ofstream outputFile("output.txt");
    if(outputFile.is_open()){
        outputFile << "Current age: " << c_age << endl;
        outputFile << "Retirement age: " << r_age << endl;

        outputFile << "Principal: " << principal << endl;
        outputFile << "Current Salary: " << c_salary << endl;
        outputFile << "Percentage to save: " << percent_to_save << endl << endl;

        outputFile << "Yearly contributing amount: " << (c_salary*percent_to_save)/(r_age-c_age) << endl;
        outputFile << "Yearly compounded interest: " << c_interest / (r_age - c_age);
        outputFile.close();
    }else{
        cout << "Unable to output to file!";
    }

    return 0;
}