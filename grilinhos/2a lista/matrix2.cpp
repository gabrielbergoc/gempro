#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void create_matrix(int matrix[5][5]) {
    for (int i{0}; i < 5; i++) {
        for (int j{0}; j < 5; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

void print_matrix(int matrix[5][5]) {
    for (int i{0}; i < 5; i++) {
        for (int j{0}; j < 5; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int sum_diag(int matrix[5][5]) {
    int sum{0};
    for (int i{0}; i < 5; i++) {
        sum += matrix[i][i];
    }

    return sum;
}

int main() {
    int matrix[5][5];

    srand((unsigned) time(0));

    create_matrix(matrix);
    print_matrix(matrix);

    cout << sum_diag(matrix) << endl;
}