#include <iostream>

using namespace std;

int sort(int* a, int* b, int* c) {

    if (*a == *b && *b == *c) {
        return 1;
    }

    int array[]{*a, *b, *c};
    int temp{*a};
    bool changed{true};

    while (changed) {
        changed = false;
        for (int i{0}; i < 2; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                changed = true;
            }
        }
    }
    
    *a = array[0];
    *b = array[1];
    *c = array[2];

    return 0;

}

int main() {
    int a{0};
    int b{0};
    int c{0};

    cout << "Enter 3 integers: ";
    cin >> a >> b >> c;

    sort(&a, &b, &c);

    cout << "Ordered values: " << a << " " << b << " " << c << endl;
}