#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int count = 0;
    // Generate all possible subsets using bitmasking
    for (int mask = 0; mask < (1 << N); ++mask) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if (sum % 2 == 0) {
            count++;
        }
    }

    cout << "Number of subsets with even sum: " << count << "\n";

    return 0;
}