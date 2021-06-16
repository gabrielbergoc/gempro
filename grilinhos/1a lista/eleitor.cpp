#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int birth_year{0}, age{0};
    time_t now = time(0);
    tm *local = localtime(&now);
    int today_year = 1900 + local->tm_year;

    cin >> birth_year;

    age = today_year - birth_year;
    cout << age << endl;

    if (age >= 18 && age <= 70) {
        cout << "Voto obrigatorio" << endl;
    } else if(age < 16) {
        cout << "Nao pode votar" << endl;
    } else {
        cout << "Voto facultativo" << endl;
    }
}