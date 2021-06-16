/*
Adds two integers input by the user
*/

#include <iostream>

int main() {
    // declaring variables
    int n1{0};
    int n2{0};
    int sum{0};
    // in this case, all variables were initialized to 0 (list initialization)

    std::cout << "Enter first integer: "; // prompts user
    // "'std::cout' gets the string 'Enter first integer: '"
    std::cin >> n1; // attributes number read to variable n1
    // "'std::cin' gives (a value to) n1"

    std::cout << "Enter second integer: ";
    std::cin >> n2;

    sum = n1 + n2;

    std::cout << "Result: " << sum << std::endl; // prints sum to the screen
    // concatenation of stream insertion (multiple '<<' operators)

    // 'endl' outputs a newline and flushes the output buffer
}