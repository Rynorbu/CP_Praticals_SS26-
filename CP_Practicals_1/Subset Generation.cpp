#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> elements(N);
    cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; ++i) {
        cin >> elements[i];
    }

    // Total number of subsets = 2^N
    int totalSubsets = 1 << N; 

    cout << "\nAll possible subsets:\n";

    // Iterate through all possible subsets using bitmask
    for (int mask = 0; mask < totalSubsets; ++mask) {
        cout << "{ ";
        // Check each bit in the mask
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                cout << elements[i] << " ";
            }
        }
        cout << "}\n";
    }

    return 0;
}
