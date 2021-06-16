#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand((unsigned) time(0));
    int n = rand() % 1024 + 1;

    int guess{0};
    
    do {
        cin >> guess;

        if (guess == n) {
            cout << "You got it right!" << endl;
        } else if (guess < n) {
            cout << "Too low, try again" << endl;
        } else {
            cout << "Too high, try again" << endl;
        } 
    } while (guess != n);
    
}