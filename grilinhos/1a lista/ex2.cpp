#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a{234.345};
    double b{45.698};

    cout << fixed;
    cout << a << " - " << b << endl;

    cout << setprecision(0);
    cout << a << " - " << b << endl;

    cout << setprecision(1);
    cout << a << " - " << b << endl;

    cout << setprecision(2);
    cout << a << " - " << b << endl;

    cout << setprecision(3);
    cout << a << " - " << b << endl;

    cout << setprecision(6) << scientific;
    cout << a << " - " << b << endl;

    cout << uppercase;
    cout << a << " - " << b << endl;

}