#include <iostream>

using namespace std;

int main() {
    int codigo{0};

    cin >> codigo;

    if (codigo == 1) {
        cout << "Alimento nao-perecivel." << endl;
    } else if (codigo > 1 && codigo <= 4) {
        cout << "Alimento perecivel." << endl;
    } else if (codigo > 4 && codigo <= 6) {
        cout << "Vestuario." << endl;
    } else if (codigo == 7) {
        cout << "Higiene pessoal." << endl;
    } else if (codigo > 7 && codigo <= 15) {
        cout << "Limpeza e utensilios domesticos." << endl;
    } else {
        cout << "Codigo invalido." << endl;
    }
}