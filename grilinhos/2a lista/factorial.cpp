#include <iostream>

using namespace std;

int factorial(int n) {
    int res{1};

    for (n; n > 0; n--) {
        res *= n;
    }

    return res;
}

int main() {
        int n{0};

    cin >> n;

    cout << factorial(n) << endl;
}