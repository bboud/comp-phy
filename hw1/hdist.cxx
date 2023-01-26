#include <iostream>
#include <math.h>

double pi = 3.1415926536;

// Convert the input degrees into radians.
double deg2rad( int degrees ){
	return 2*pi*degrees / 360;
}

int main(){
	using namespace std;

	//Variables used to store the input.
	double v_i, theta;

	// Output prompts and gather inputs.
	cout << "What is the initial velocity of the object? (m/s): ";
	cin >> v_i;
	cout << "What is the angle at which the object was thrown? (degrees): ";
	cin >> theta;
	
	// Output the result of the x-distance calculation.
	cout << "The horizontal distance is " << v_i * v_i * sin(2*deg2rad(theta)) / 9.81 << "m." << endl;

	return 0;
}
