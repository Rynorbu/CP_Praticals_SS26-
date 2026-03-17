#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> line;  // Deque to store the people in the line

    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int operation;
        cout << "Enter operation (1: push_front, 2: push_back, 3: pop_front, 4: pop_back): ";
        cin >> operation;

        switch (operation) {
            case 1: {
                int x;
                cout << "Enter the person to add at the front: ";
                cin >> x;
                line.push_front(x);
                break;
            }
            case 2: {
                int x;
                cout << "Enter the person to add at the back: ";
                cin >> x;
                line.push_back(x);
                break;
            }
            case 3: {
                if (!line.empty()) {
                    line.pop_front();
                } else {
                    cout << "Line is empty.\n";
                }
                break;
            }
            case 4: {
                if (!line.empty()) {
                    line.pop_back();
                } else {
                    cout << "Line is empty.\n";
                }
                break;
            }
            default:
                cout << "Invalid operation.\n";
        }

        // Print the contents of the line
        cout << "Contents of the line: ";
        for (const int& person : line) {
            cout << person << " ";
        }
        cout << "\n";
    }

    return 0;
}
