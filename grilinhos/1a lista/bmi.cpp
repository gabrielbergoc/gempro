#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double height{0};
    double weight{0};
    double bmi{0};

    cout << "Enter height (meters): ";
    cin >> height;

    cout << "Enter weight (kg): ";
    cin >> weight;

    bmi = weight / (height * height);
    cout << fixed << setprecision(2) << "Your body mass index is " << bmi << endl;

    if (bmi < 20) {
        cout << "You are underweight." << endl;
    } else if (bmi >= 20 && bmi < 25) {
        cout << "Your BMI is normal." << endl;
    } else if (bmi >= 25 && bmi < 30) {
        cout << "You are overweight." << endl;
    } else if (bmi >= 30 && bmi < 35) {
        cout << "You have class I obesity." << endl;
    } else if (bmi >= 35 && bmi < 40) {
        cout << "You have class II obesity." << endl;
    } else {
        cout << "You have class III obesity." << endl;
    }
}