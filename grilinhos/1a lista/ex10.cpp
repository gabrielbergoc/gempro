#include <iostream>

using namespace std;

int main() {
    int value{0};
    int count_even{0};
    int count_odd{0};
    int count_positive{0};
    int count_negative{0};

    for (int i = 0; i < 5; i++) {
        cin >> value;

        if (value < 0) {
            count_negative++;
        } else  if (value > 0) {
            count_positive++;
        }

        if (value % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    cout << "Odds: " << count_odd << endl;
    cout << "Evens: " << count_even << endl;
    cout << "Positives: " << count_positive << endl;
    cout << "Negatives: " << count_negative << endl;

}