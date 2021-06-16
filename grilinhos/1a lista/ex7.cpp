#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int calc_roots(double abc[3], double roots[2]) {
    double delta{0};
    double a = abc[0], b = abc[1], c = abc[2];

    delta = b*b - 4*a*c;

    if (delta < 0) {
        return 0;
    } else if (delta == 0) {
        roots[0] = (-b + sqrt(delta)) / (2*a);
        return 1;
    } else {
        roots[0] = (-b + sqrt(delta)) / (2*a);
        roots[1] = (-b - sqrt(delta)) / (2*a);
        return 2;
    }
}

bool isTriangle(double abc[3]) {
    double shorter_sides[2];
    double longest_side{0};
    int i{0}, j{0}, k{0};

    longest_side = max({abc[0], abc[1], abc[2]});

    for (i; i < 3; i++) {
        if ((abc[i] == longest_side) && (k = 0)) {
            k++;
        } else {
            shorter_sides[j] = abc[i];
            j++;
        }
    }

    if (shorter_sides[0] + shorter_sides[1] > longest_side) {
        return true;
    } else {
        return false;
    }
}

double areaTriangle(double abc[3]) {
    double semiP{0};
    double area{0};

    semiP = (abc[0] + abc[1] + abc[2]) / 2;

    area = sqrt(semiP * (semiP - abc[0]) * (semiP - abc[1]) * (semiP - abc[2]));

    return area;
}

double areaTrapezium(double abc[3]) {
    double area{0};

    area = (abc[0] + abc[1]) * abc[2] / 2;

    return area;
}

double seriesResist(double abc[3]) {
    return abc[0] + abc[1] + abc[2];
}

double paralelResist(double abc[3]) {
    double equiv_resist{0};

    equiv_resist = (1 / abc[0]) + (1 / abc[1]) + (1 / abc[2]);

    return 1 / equiv_resist;
}

bool arePositive(double abc[3]) {
    bool isPositive = true;
    int i{0};

    while (isPositive && (i < 3)) {
        if (abc[i] < 0) {
            isPositive = false;
        }
        i++;
    }

    return isPositive;
}

int main() {
    double abc[3];
    int x{0};

    cin >> abc[0] >> abc[1] >> abc[2] >> x;

    if (x == 1) {
        double roots[2];
        int n_roots{0};

        n_roots = calc_roots(abc, roots);

        cout << "Number of roots: " << n_roots << endl;

        for (int i = 0; i < n_roots; i++) {
            cout << "Root #" << i + 1 << ": " << roots[i] << " " << endl;
        }
    } else if (x == 2) {
        if (isTriangle(abc)) {
            cout << areaTriangle(abc) << endl;
        } else {
            cout << "Can't form a triangle." << endl;
        }
    } else if (x == 3) {
        if (arePositive(abc)) {
            cout << areaTrapezium(abc) << endl;
        } else {
            cout << "Isn't a trapezium." << endl;
        }
    } else if (x == 4) {
        if (arePositive(abc)) {
            cout << "Equivalent resistance (series): " << seriesResist(abc) << endl;
            cout << "Equivalent resistance (paralel): " << paralelResist(abc) << endl;
        } else {
            cout << "Invalid value(s)." << endl;
        }
    } else {
        cout << "Error: invalid input (last number must be between 1 and 4)" << endl;
    }
    
}