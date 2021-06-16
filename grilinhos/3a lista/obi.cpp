#include <iostream>

using namespace std;

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int M{0};
    int A{0};
    int B{0};
    int C{0};

    cin >> M >> A >> B;

    C = M - A - B;

    cout << max(max(A, B), C) << endl;
}