#include <iostream>

using namespace std;

int fibonacci(int n) {
    int n1{0}, n2{1}, n3{1};

    for (n; n > 1; n--) {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
    }

    return n1;
}

int fibonacci2(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci2(n - 1) + fibonacci2(n - 2);
    }
}

int main() {
    int n{0};

    cin >> n;

    cout << "Iterative: " << fibonacci(n) << endl;
    cout << "Recursive: " << fibonacci2(n) << endl;
}