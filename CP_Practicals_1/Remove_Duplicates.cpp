#include <iostream>
#include <vector>   
#include <algorithm>

using namespace std;

int main() {
    int N;
    cout << "Enter the number of integers: ";
    cin >> N;  

    vector<int> numbers(N);  

    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];  // Read each integer into the vector
    }

    // sort the vector to bring duplicates together
    sort(numbers.begin(), numbers.end());

    // Use unique to remove duplicates and get the new end iterator
    auto last = unique(numbers.begin(), numbers.end());

    // Erase the "removed" elements from the vector
    numbers.erase(last, numbers.end());

    // Print the unique values
    cout << "Unique values:\n";
    for (int num : numbers) {
        cout << num << " ";  
    }
    cout << "\n";  

    return 0;
}