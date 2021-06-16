/*
Olimpíada Brasileira de Informática 2020
Nível Sênior
Fase Local

Fissura Perigosa

A erupção do vulcão Kilauea em 2018 no Havaí atraiu a atenção de todo o mundo. Inicialmente
a força da erupção era menor e a lava avançou para o sul com relativamente poucos danos. Após
algumas semanas, porém, a fissura 8 começou a jorrar com mais força e a lava avançou também
para o norte trazendo muita destruição.

Você está ajudando na implementação de um sistema para simular a área por onde a lava avançaria,
em função da força da erupção. O mapa será representado simplificadamente por uma matriz
quadrada de caracteres, de 1 a 9, indicando a altitude do terreno em cada posição da matriz. Vamos
considerar que a fissura 8, por onde a erupção se inicia, está sempre na posição do canto superior
esquerdo da matriz. Dada a força da erupção, que será um valor inteiro, de 0 a 9, seu programa deve
imprimir a matriz de caracteres representando o avanço final da lava. Se a lava consegue invadir
uma posição da matriz, o caractere naquela posição deve ser trocado por um asterisco (‘*’). Uma
posição será invadida pela lava se seu valor for menor ou igual à força da erupção e

• for a posição inicial; ou
• estiver adjacente, ortogonalmente (abaixo, acima, à esquerda ou à direita), a uma posição
invadida.

Entrada:
A primeira linha da entrada contém dois inteiros N e F representando, respectivamente o número
de linhas (que é igual ao de colunas) da matriz e a força da erupção. Cada uma das N linhas
seguintes contém uma string de N caracteres, entre 1 e 9, indicando o mapa de entrada.

Saída:
Seu programa deve imprimir N linhas contendo, cada uma, N caracteres representando o avanço
final da lava de acordo com o enunciado.
Restrições
• 1 ≤ N ≤ 500
• 0 ≤ F ≤ 9

Exemplos:

in:
8 6
2 7 7 5 5 4 7 8
2 9 9 8 5 4 3 9
3 4 8 9 9 9 8 9
2 2 1 1 5 5 6 9
6 6 7 3 6 6 8 9
9 9 8 8 6 5 5 5
4 4 4 3 3 3 9 9
9 9 9 8 6 9 9 1

out:
*7755478
*9985439
**899989
*******9
**7***89
9988****
******99
9998*991

------------------

in:
5 4
2 5 6 7 9
3 5 2 3 4
1 7 1 8 2
3 9 9 9 3
1 1 2 2 3

out:
*5679
*5***
*7*8*
*999*
*****

-----------------

in:
2 8
9 1
1 1

out:
91
11

*/

#include <iostream>

using namespace std;

// recursive solution
void check_path_recur(int matrix[500][500], int i, int j, int n, int f) {

    // if this position has a value greater than or equal to eruption force
    // and isn't zero (to avoid infinite recursions), change value to zero
    // (to signify lava)
    if (matrix[i][j] <= f && matrix[i][j] > 0) {
        matrix[i][j] = 0;

        // check each adjacent position (if inside bounds)
        if (i < n - 1) {
            check_path_recur(matrix, i + 1, j, n, f);
        }
        if (j < n - 1) {
            check_path_recur(matrix, i, j + 1, n, f);
        }
        if (i > 0) {
            check_path_recur(matrix, i - 1, j, n, f);
        }
        if (j > 0) {
            check_path_recur(matrix, i, j - 1, n, f);
        }

    }
    // else: do nothing

    // the resulting algorithm follows the path of the lava first down, then
    // to the right, then up, then to the left
}

// iterative solution - doesn't work if the matrix is too big (stack overflow)
void check_path_iter(int matrix[500][500], int n, int f) {

    bool changed = true;    // variable to keep track of changes

    int sub_matrix_size = 2;    // we'll increment this variable in each
                                // iteration to expand the submatrix we want
                                // to check (we don't need to check the whole
                                // matrix everytime)

    while (changed) {   // if it hasn't been any changes, it means there's no
                        // more paths for the lava to flow

        // variables to keep track of surrounding positions
        // can't be zero, because zero means lava, and can't be a positive
        // integer, which would cause errors in checking
        int left = -1, right = -1, up = -1, down = -1;

        changed = false;

        // loops to check the submatrix
        for (int i = 0; i < sub_matrix_size; i++) {
            for (int j = 0; j < sub_matrix_size; j++) {

                // get values of adjacent positions (if inside bounds)
                if (i > 0) {
                    up = matrix[i - 1][j];
                }
                if (i < sub_matrix_size - 1) {
                    down = matrix[i + 1][j];
                }
                if (j > 0) {
                    left = matrix[i][j - 1];
                }
                if (j < sub_matrix_size - 1) {
                    right = matrix[i][j + 1];
                }

                // if value is less than or equal eruption force AND different
                // than zero (to avoid infinite loops) AND has lava in any
                // adjacent position: change it to zero (i.e. now has lava)
                if (matrix[i][j] <= f && matrix[i][j] > 0 
                    && (up == 0 || down == 0 || left == 0 || right == 0)) {

                    matrix[i][j] = 0;

                    // if there's at least one change, continue looping
                    changed = true;
                }
            }
        }

        // increment submatrix's size in each iteration until it is the size
        // of the whole matrix
        if (sub_matrix_size < n) {
            sub_matrix_size++;
        }
    }
}

int main() {
    
    int n{0};   // n = size of the matrix
    int f{0};   // f = force of eruption

    // get inputs
    cin >> n >> f;
    int matrix[500][500];
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //check_path_recur(matrix, 0, 0, n, f);

    // if we're using the iterative solution, we must first check if the first
    // position will be flooded with lava then change it, otherwise there would
    // be another conditional in the already big algorithm
    if (matrix[0][0] <= f) {
        matrix[0][0] = 0;
        check_path_iter(matrix, n, f);
    }

    // print matrix changing each zero for '*' as asked in the enunciate
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            if (matrix[i][j] == 0) {
                cout << '*';
            } else {
                cout << matrix[i][j];
            }
        }
        cout << endl;
    }
}