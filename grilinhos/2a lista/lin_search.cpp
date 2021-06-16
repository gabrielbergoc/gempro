#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void populate_array(int A[100]) {
    for (int i{0}; i < 100; i++) {
        A[i] = rand() % 1000 + 1;
    }
}

void print_array(int A[100]) {
    for (int i{0}; i < 100; i++) {
        cout << setw(5) << A[i];
    }
    cout << endl;
}

int search_array(int A[100], int n) {
    bool found = false;

    int i{0};
    while (i < 100 && !found) {
        if (A[i] == n) {
            found = true;
            break;
        }
        i++;
    }

    if (found) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    srand((unsigned) time(0));

    int A[100];
    populate_array(A);
    // print_array(A);

    int n{0};
    cout << "Choose a number between 1 and 1000: ";
    cin >> n;

    int index = search_array(A, n);

    if (index >= 0) {
        cout << "Number found at index " << index << endl;
    } else {
        cout << "Number not found :(" << endl;
    }
    
}