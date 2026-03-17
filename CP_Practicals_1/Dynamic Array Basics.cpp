#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Enter the number of integers: ";
    cin >> N;  

    // Create a dynamic vector to store N integers
    vector<int> numbers(N); 
    
    // Read N integers from the user and store them in the vector
    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i]; 
    }

    // Initialize variables to track maximum, minimum, and sum
    int maxElement = numbers[0];  
    int minElement = numbers[0];  
    int sum = 0;  

    // Loop through all integers to find max, min, and calculate sum
    for (int num : numbers) {
        if (num > maxElement) {
            maxElement = num;
        }
        if (num < minElement) {
            minElement = num;
        }
        sum += num;
    }

    // Display the results (maximum, minimum, and sum)
    cout << "Maximum element: " << maxElement << "\n";
    cout << "Minimum element: " << minElement << "\n";
    cout << "Sum of elements: " << sum << "\n";

  return 0;
}