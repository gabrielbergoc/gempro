/*
This programs takes an undefined number of scores between 0 and 100 and prints
the average.
There are examples of static type casting and float formatting.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n{0};
    int counter{0};
    int sum{0};
    double average{0};

    cout << "Enter a score (or -1 to finish): ";
    cin >> n;

    while (n != -1) {
        if (n >= 0 && n <= 100) {
            sum += n;
            counter++;
        } else {
            cout << "Not a valid number. Please input an integer between 0 and 100\n";
        }
        cout << "Enter a score (or -1 to finish): ";
        cin >> n;
    }

    // converts sum to float explicitly. compiler converts counter implicitly
    average = static_cast<float>(sum) / counter;

    // format float to 2 decimal places and to fixed-point (not scientific notation)
    cout << setprecision(2) << fixed;

    cout << "The average is " << average << endl;
}