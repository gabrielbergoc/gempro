#include <iostream>
#include <cmath>

using namespace std;

double calc_delta(double a, double b, double c) {
    return (b*b) - (4*a*c);
}

void bhaskara(double a, double b, double c, 
                double delta, 
                double *root1, double *root2) {

    *root1 = (-b + sqrt(delta)) / (2*a);
    *root2 = (-b - sqrt(delta)) / (2*a);
}

void print(double a, double b, double c, 
                double delta, 
                double root1, double root2) {
    
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    // cout << "Delta: " << delta << endl;

    if (delta > 0 && a != 0) {
        cout << "Root 1: " << root1 << endl;
        cout << "Root 2: " << root2 << endl;
    } else if (delta == 0 && a != 0) {
        cout << "Root: " << root1 << endl;
    } else if (a != 0) {
        cout << "No real roots." << endl;
    } else {
        cout << "Not a 2nd degree polynomial." << endl;
    }
    cout << endl;
}

int main() {
    double coefs[3];
    cin >> coefs[0] >> coefs[1] >> coefs[2];

    double root1{0}, root2{0}, delta{0};
    double a{0}, b{0}, c{0};

    int indexes[5] = {0, 1, 2, 0, 1};
    
    for (int i{0}; i < 3; i++) {

        a = coefs[indexes[i]];
        b = coefs[indexes[i + 1]];
        c = coefs[indexes[i + 2]];

        delta = calc_delta(a, b, c);

        if (delta >= 0 && a != 0) {
            bhaskara(a, b, c, delta, &root1, &root2);
        }

        print(a, b, c, delta, root1, root2);
    }

    for (int i{4}; i >= 0; i--) {

        a = coefs[indexes[i]];
        b = coefs[indexes[i - 1]];
        c = coefs[indexes[i - 2]];

        delta = calc_delta(a, b, c);

        if (delta >= 0 && a != 0) {
            bhaskara(a, b, c, delta, &root1, &root2);
        }

        print(a, b, c, delta, root1, root2);
    }

}