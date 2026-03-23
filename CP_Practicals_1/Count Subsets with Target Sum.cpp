#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int N, target;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    int countSubsets = 0;

    // Generate all subsets using bit manipulation
    for (int i = 0; i < (1 << N); i++) { // Loop from 0 to 2^N - 1
        int subsetSum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) { // Check if the j-th element is included
                subsetSum += arr[j];
            }
        }
        // Check if the subset sum equals the target
        if (subsetSum == target) {
            countSubsets++;
        }
    }

    cout << "Number of subsets with sum equal to " << target << ": " << countSubsets << endl;

    return 0;
}
