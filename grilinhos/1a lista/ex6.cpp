#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double n1{0}, n2{0}, n3{0}, me{0}, ma{0};

    cin >> n1 >> n2 >> n3 >> me;

    ma = (n1 + 2*n2 + 3*n3 + me) / 7;

    cout << fixed << setprecision(2) << ma << endl;

    if (ma >= 9) {
        cout << "A" << endl;
    } else if (ma >= 7.5) {
        cout << "B" << endl;
    } else if (ma >= 6) {
        cout << "C" << endl;
    } else{
        cout << "D" << endl;
    }
}