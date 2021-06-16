#include <iostream>

using namespace std;

const double PI{3.1415};

void calc_esfera(double R, double* area, double* volume) {
    *area = 4 * PI * R * R;
    *volume = PI * R * R * R * 4 / 3;
}

int main() {
    double area{0};
    double volume{0};
    double radius{0};

    cin >> radius;

    calc_esfera(radius, &area, &volume);

    cout << "Area: " << area << "\nVolume: " << volume << endl;
}