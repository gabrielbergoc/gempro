#include <iostream>

using namespace std;

int main() {
    double n{0};

    cout << "Enter a negative number: ";
    cin >> n;

    while (n >= 0) {
        cout << "Only negative numbers, please: ";
        cin >> n;
    }

}