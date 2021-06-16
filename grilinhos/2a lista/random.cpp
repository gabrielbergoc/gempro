#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // max value returned by rand()
    cout << RAND_MAX << endl;
    
    // always the same "random" number
    cout << rand() << endl;

    // set current time as seed to get pseudo random numbers
    srand((unsigned) time(0));
    cout << rand() << endl;

    // random numbers between 0 and 1 (excluding)
    cout << (double) rand() / RAND_MAX << endl;

    // random number either 0 or 1
    cout << rand() % 2 << endl;

    // random numbers between 1 and 10 (including)
    cout << rand() % 10 + 1 << endl;
}