#include <iostream>
#include <deque>

using namespace std;

// Function to add person at the front
void pushFront(deque<int>& line, int x) {
    line.push_front(x);
    cout << "Added " << x << " at the front.\n";
}

// Function to add person at the back
void pushBack(deque<int>& line, int x) {
    line.push_back(x);
    cout << "Added " << x << " at the back.\n";
}

// Function to remove person from the front
void popFront(deque<int>& line) {
    if (!line.empty()) {
        cout << "Removed " << line.front() << " from the front.\n";
        line.pop_front();
    } else {
        cout << "Line is empty. Cannot remove from front.\n";
    }
}

// Function to remove person from the back
void popBack(deque<int>& line) {
    if (!line.empty()) {
        cout << "Removed " << line.back() << " from the back.\n";
        line.pop_back();
    } else {
        cout << "Line is empty. Cannot remove from back.\n";
    }
}

// Function to print the line contents
void printLine(const deque<int>& line) {
    cout << "Contents of the line: ";
    if (line.empty()) {
        cout << "(empty)";
    } else {
        for (const int& person : line) {
            cout << person << " ";
        }
    }
    cout << "\n";
}

int main() {
    deque<int> line;  // Deque to store the people in the line

    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int operation;
        cout << "\nEnter operation (1: push_front, 2: push_back, 3: pop_front, 4: pop_back): ";
        cin >> operation;

        if (operation == 1) {
            int x;
            cout << "Enter the person to add at the front: ";
            cin >> x;
            pushFront(line, x);
        } else if (operation == 2) {
            int x;
            cout << "Enter the person to add at the back: ";
            cin >> x;
            pushBack(line, x);
        } else if (operation == 3) {
            popFront(line);
        } else if (operation == 4) {
            popBack(line);
        } else {
            cout << "Invalid operation.\n";
        }

        printLine(line);
    }

    return 0;
}
