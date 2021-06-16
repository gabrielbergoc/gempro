#include <iostream>

using namespace std;

int sum(int n) {
    int sum{0};

    for (int i{1}; i <= n; i++) {
        sum += i;
    }

    return sum;
}

int sum2(int n) {
    if (n < 1) {
        return -1;
    } else if (n == 1) {
        return 1;
    } else {
        return n + sum2(n - 1);
    }
}

int main() {
    int n{0};
    cin >> n;

    cout << "Iterative: " << sum(n) << endl;
    cout << "Recursive: " << sum2(n) << endl;

    
}