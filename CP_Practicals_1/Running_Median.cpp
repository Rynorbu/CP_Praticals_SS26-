#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        if (maxHeap.empty() || arr[i] <= maxHeap.top()) {
            maxHeap.push(arr[i]);
        } else {
            minHeap.push(arr[i]);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Print the median
        if (maxHeap.size() == minHeap.size()) {
            cout << "Median: " << (maxHeap.top() + minHeap.top()) / 2.0 << endl;
        } else {
            cout << "Median: " << maxHeap.top() << endl;
        }
    }

    return 0;
}
