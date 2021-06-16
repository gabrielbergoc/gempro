#include <iostream>
#include <iomanip>

using namespace std;

int count_words(char* string);

int main() {
    cout << "Enter a sentence (max. 80 characters): ";

    char sentence[80];
    cin.getline(sentence, 80);

    cout << count_words(sentence) << endl;
}

int count_words(char* string) {
    int counter{1};
    char prev;

    for (int i{0}; i < 80 && string[i]; i++) {
        if (string[i] == ' ' && prev != ' ') {
            counter++;
        }
        prev = string[i];
    }

    return counter;
}
