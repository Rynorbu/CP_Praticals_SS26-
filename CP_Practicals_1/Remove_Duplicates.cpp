// Given N integers, remove duplicates and print unique values. 
// Example 
// Input 
// N = 7 and elements 1 2 2 3 4 4 5 
// Output 
// 1 2 3 4 5 
// Hint: Store numbers in a vector and sort them first.

#include <iostream>
#include <vector>   
#include <algorithm> // for sort and unique

using namespace std;

int main() {
    int N;
    cout << "Enter the number of integers: ";
    cin >> N;  // Read the number of integers

    vector<int> numbers(N);  // Create a vector to store N integers

    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];  // Read each integer into the vector
    }

    // Step 1: Sort the vector to bring duplicates together
    sort(numbers.begin(), numbers.end());

    // Step 2: Use unique to remove duplicates and get the new end iterator
    auto last = unique(numbers.begin(), numbers.end());

    // Step 3: Erase the "removed" elements from the vector
    numbers.erase(last, numbers.end());

    // Step 4: Print the unique values
    cout << "Unique values:\n";
    for (int num : numbers) {
        cout << num << " ";  // Print each unique element followed by a space
    }
    cout << "\n";  // Print a newline at the end

    return 0;
}