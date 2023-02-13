/**
* For these problems you are not allowed to use the STL container classes, you have to use the C/C++ arrays.
*
* 1) Define an array of a fixed size of 20. Fill it with random numbers ranging from 1-100. Implement the simplest sort algorithm, the so called bubble-sort
* algorithm (look it up). Remark: Our swap function we discussed in class might be useful. And print out the sorted array.
*
* 2) Define a dynamic array (the array size is given as an interactive input). Fill this array with random numbers ranging from 1-50. Write function(s) to
* calculate the mean and the standard deviation of the array. Inclue also a combined function which returns you both mean and standard deviation (you have to use call-by-reference).
*/

#include <iostream>
#include <ctime>
#include <cmath>

void fixed_array();
void dynamic_array();

// Perform the sort
void bubble_sort( int *arr, int size );

// Pass by reference
void mean_std(int *arr, int size, double &mean, double &std);

int main(){
    fixed_array();
    dynamic_array();

    return 0;
}

void fixed_array(){
    int fixed[20];

    // Provide seed
    std::srand(std::time(nullptr));

    std::cout << "Unsorted List:\n";

    // Generate randoms
    for(int i = 0; i < 20; i++){
        fixed[i] = std::rand() % 100;
        std::cout << fixed[i] << std::endl;
    }

    bubble_sort(fixed, 20);

    std::cout << "Sorted list:\n";
    // Print Sort
    for(int i = 0; i < 20; i++){
        std::cout << fixed[i] << std::endl;
    }

}
void dynamic_array(){
    int *dynamic;

    // Provide seed
    std::srand(std::time(nullptr));

    // Number chosen by the user
    int n;

    // Initialize the values.
    double std = 0;
    double mean = 0;

    std::cout << "Now we will generate an array with a size of your choosing: ";

    // User input
    std::cin >> n;

    // Allocate
    dynamic = (int*) malloc(sizeof(int) * n);

    std::cout << "Randomly generated list of size " << n << "\n";

    // Generate randoms
    for(int i = 0; i < n; i++){
        dynamic[i] = std::rand() % 50;
        std::cout << dynamic[i] << std::endl;
    }

    //Calculate the mean and std
    mean_std(dynamic, n, mean, std);

    std::cout << "Mean: " << mean << "\nStandard Diviation: " << std << std::endl;

    // Free previous alloc at end of scope
    free(dynamic);
}

void bubble_sort( int *arr, int size ){
    // Swapped flag
    bool swapped;
    do{
        // Initialized the flag to false.
        swapped = false;

        // Loop over array to see if there needs to be a swap.
        for(int i = 0; i < size; i++){
            //If the next index is larger than the highest possible index, break the loop.
            if (i+1 > size-1) break;

            // Store copies of the values on the stack
            // Strictly speaking, making the 'now' variable isn't needed but for readability, I have chosen to use it.
            int now = arr[i];
            int next = arr[i+1];

            if(now > next){
                // Set the values at the reference points in the array to the values on the stack
                /*
                 * Alternatively, without the 'now' variable:
                 * arr[i+1] = arr[i];
                 * arr[i] = next;
                 */
                arr[i+1] = now;
                arr[i] = next;

                // If we have to swap, we want to activate this so that it is caught by the while condition
                swapped = true;
            }
        }
    }while(swapped);
}

void mean_std(int *arr, int size, double &mean, double &std){
    //Mean

    // Sum all values
    for(int i = 0; i < size; i++){
        // Dereference for the assign
        mean += arr[i];
    }

    // Divide by the size.
    mean /= size;

    //STD
    for(int i = 0; i < size; i++){
        std += pow( arr[i] - mean,2);
    }

    std /= size;
    std = sqrt(std);
}