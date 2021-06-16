#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double hip{0}, cat_a{0}, cat_b{0};
    double sides[3];
    int sqr_cat_sum{0};
    int i;

    cin >> sides[0] >> sides[1] >>  sides[2];

    hip = max({sides[0], sides[1], sides[2]});

    for (i = 0; i < 3; i++) {
        if (sides[i] != hip) {
            sqr_cat_sum += sides[i] * sides[i];
        }
    }

    if (hip * hip == sqr_cat_sum){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}