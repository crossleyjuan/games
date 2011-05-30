#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int matrix[10][10];

void calcMatrix() {
    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            int val = rand() % 10;
            matrix[x][y] = val;
        }
    }
}

int main(int argc, char *argv[])
{


    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }

    getchar();
}
