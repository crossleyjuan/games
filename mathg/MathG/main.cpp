#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int matrix[10][10];

int score;

void calcMatrix() {
//    // Clean the grid
//    for (int y = 0; y < 20; y++) {
//        for (int x = 0; x < 20; x++) {
//            matrix[x][y] = 0;
//        }
//    }
    srand ( time(NULL) );
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            int val = rand() % 10;
            matrix[x][y] = val;
        }
    }
}

void printMatrix() {
    for (int x = 0; x < 10; x++)
    {
       printf("\n");
    }
    printf("Score: %d\n", score);
    printf("   ");
    for (int y = 0; y <= 9; y++) {
        printf(" %d", y);
    }
    printf("\n\n");
    for (int y = 0; y <= 9; y++) {
        printf("%d - ", y);
        for (int x = 0; x <= 9; x++) {
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }
}

int processRow(int result, int x, int y) {
    int calc = 0;
    x++;
    int start = x;
    int matches = 0;
    while (x < 10) {
        int cell = matrix[x][y];
        calc += cell;
        if (result == calc) {
            matches++;
            break;
        }
        if (calc > result) {
            break;
        }
        matches++;
        x++;
    }
    if (matches > 0) {
        for (int i = start; i < 10; i++) {
            if ((i + matches) < 10) {
                matrix[i][y] = matrix[i + matches][y];
                matrix[i + matches][y] = 0;
            } else {
                matrix[i][y] = 0;
            }
        }
    }
    return matches;
}

int processCol(int result, int x, int y) {
    int calc = 0;
    y--;
    int start = y;
    int matches = 0;
    while (y > 0) {
        int cell = matrix[x][y];
        calc += cell;
        if (result == calc) {
            matches++;
            break;
        }
        if (calc > result) {
            break;
        }
        matches++;
        y--;
    }
    if (matches > 0) {
        for (int i = start; i > 0; i--) {
            if ((i - matches) > -1) {
                matrix[x][i] = matrix[x][i - matches];
                matrix[x][i - matches] = 0;
            } else {
                matrix[x][i] = 0;
            }
        }
    }
    return matches;
}

void processPos(int x, int y) {
    int result = matrix[x][y];
    int resRow = processRow(result, x, y);
    int resCol = processCol(result, x, y);
    if (resRow > 0 || resCol > 0) {
        matrix[x][y] = 0;
    }
    score += (resRow * 10) + (resCol * 10);
}

int main(int argc, char *argv[])
{
    score = 0;
    calcMatrix();

    int x, y = 0;
    while (x != 99) {
        printMatrix();

        printf("X:");
        scanf("%d", &x);
        printf("Y:");
        scanf("%d", &y);

        processPos(x, y);
    }

    getchar();
}
