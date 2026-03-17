#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, K;
    cout << "Enter the number of elements (N) and window size (K): ";
    cin >> N >> K;  // Read the number of elements and window size

    vector<int> arr(N);  // Create a vector to store N integers

    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];  // Read each integer into the vector
    }

    deque<int> dq;  // Deque to store indices of useful elements
    vector<int> result;  // Vector to store the maximums of each window

    for (int i = 0; i < N; ++i) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }

        // Remove indices whose corresponding values are less than arr[i]
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add current index to the deque
        dq.push_back(i);

        // If we've hit the size of the window, add the maximum to the result
        if (i >= K - 1) {
            result.push_back(arr[dq.front()]);  // The front of the deque is the max
        }
    }

    // Print the maximums of each window
    cout << "Maximums of each window:\n";
    for (int maxVal : result) {
        cout << maxVal << " ";  // Print each maximum followed by a space
    }
    cout << "\n";  // Print a newline at the end

    return 0;
}