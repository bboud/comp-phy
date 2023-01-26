#include <iostream>

double pi = 3.1415926536;

double deg2rad( int degrees ){
	return 2*pi*degrees / 360;
}

int main(){

	using namespace std;

	//Variable to store the input.
	double degrees;

	// Prompt and store the input.
	cout << "What is the number in degrees: ";

	cin >> degrees;

	// Call the conversion function and output it to the user.
	cout << degrees << " is " << deg2rad(degrees) << " radians." << endl;

	return 0;
}
