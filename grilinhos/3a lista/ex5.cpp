#include <iostream>

using namespace std;

bool isPrime(int* n) {
    bool prime{true};

    for (int i = *n / 2; i >= 2 && prime; i--) {
        if (*n % i == 0) {
            prime = false;
        }
    }

    return prime;
}

int main() {
    int n{0};

    cin >> n;

    for (int i{1}; i <= n; i++) {
        cout << i << ": " << isPrime(&i) << endl;
    }
}