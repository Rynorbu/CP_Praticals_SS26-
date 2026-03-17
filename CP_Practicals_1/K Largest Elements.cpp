// Given N numbers, print the K largest numbers. 
// Example 
// Input 
// N=6 K=3 and elements 7 10 4 3 20 15 
// Output 
// 20 15 10 
// Hint: Use priority_queue (max heap). 

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cout << "Enter the number of elements (N) and the number of largest elements to print (K): ";
    cin >> N >> K;

    priority_queue<int> pq;  // Max heap

    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        pq.push(x);
    }

    cout << "The " << K << " largest elements are:\n";
    for (int i = 0; i < K; ++i) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    return 0;
}