#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Enter the number of integers: ";
    cin >> N;

    vector<int> numbers(N);

    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];  
    }

    cout << "Reversed array:\n";
    for (int i = N - 1; i >= 0; --i) {  // Traverse the vector in reverse
        cout << numbers[i] << " ";
    }
    cout << "\n";

    return 0;
}
