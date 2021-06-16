#include <iostream>

using namespace std;

const int MAX_SIZE{20};


// copy contents of array A into array B
void copy_array(int A[MAX_SIZE], int B[MAX_SIZE]) {
    for (int i{0}; i < MAX_SIZE; i++) {
        B[i] = A[i];
    }
}

// copy contents of array A into array B and insert value at index k
void insert_array(int A[MAX_SIZE], int B[MAX_SIZE], int value, int k) {
    for (int i{0}, j{0}; i < MAX_SIZE && j < MAX_SIZE; i++, j++) {
        if (j == k) {
            B[j] = value;
            j++;
        }
        B[j] = A[i];
    }
}

void print_array(int A[MAX_SIZE]) {
    for (int i{0}; i < MAX_SIZE; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int kolya[MAX_SIZE] =  {16, -5, -11, -15, 10, 5, 4, -4};
    int copyA[MAX_SIZE], copyB[MAX_SIZE];
    copy_array(kolya, copyA);
    copy_array(kolya, copyB);

    /*
    print_array(kolya);
    print_array(copyA);
    print_array(copyB);
    */

    int i{0}, j{i};
    int sum{0};

    bool inserted = true;
    while (inserted) {
        inserted = false;
        for (i = 0; i < MAX_SIZE - 1; i++) {

            // stop when encounters a 0 (end of array)
            if (copyA[i] == 0) {
                break;
            }

            sum = 0;
            for (j = i; j < MAX_SIZE; j++) {
                sum += copyA[j];
                if (sum == 0) {
                    insert_array(copyA, copyB, copyA[j] * 2, j);
                    copy_array(copyB, copyA);
                    // print_array(copyA);
                    inserted = true;
                    break;
                }
            }
            
            if (inserted) {
                break;
            }
        }
    }

    print_array(copyA);
}