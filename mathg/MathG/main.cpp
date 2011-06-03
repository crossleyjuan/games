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

int processRowRight(int result, int x, int y, bool clear) {
    int calc = 0;
    x++;
    int start = x;
    int matches = 0;
    bool found = false;
    while (x < 10) {
        int cell = matrix[x][y];
        calc += cell;
        if (result == calc) {
            matches++;
            found = true;
            break;
        }
        if (calc > result) {
            break;
        }
        matches++;
        x++;
    }
    if (clear && found) {
        for (int i = start; i < 10; i++) {
            if ((i + matches) < 10) {
                matrix[i][y] = matrix[i + matches][y];
                matrix[i + matches][y] = 0;
            } else {
                matrix[i][y] = 0;
            }
        }
    }
    if (found) {
        return matches;
    } else {
        return 0;
    }
}

int processRowLeft(int result, int x, int y, bool clear) {
    int calc = 0;
    x--;
    int start = x;
    int matches = 0;
    bool found = false;
    while (x >= 0) {
        int cell = matrix[x][y];
        calc += cell;
        if (result == calc) {
            matches++;
            found = true;
            break;
        }
        if (calc > result) {
            break;
        }
        matches++;
        x--;
    }
    if (clear && found) {
        for (int i = start; i > 0; i--) {
            if ((i - matches) > -1) {
                matrix[i][y] = matrix[i - matches][y];
                matrix[i - matches][y] = 0;
            } else {
                matrix[i][y] = 0;
            }
        }
    }
    if (found) {
        return matches;
    } else {
        return 0;
    }
}

int processColTop(int result, int x, int y, bool clear) {
    int calc = 0;
    y--;
    int start = y;
    int matches = 0;
    bool found = false;
    while (y >= 0) {
        int cell = matrix[x][y];
        calc += cell;
        if (result == calc) {
            matches++;
            found = true;
            break;
        }
        if (calc > result) {
            break;
        }
        matches++;
        y--;
    }
    if (clear && found) {
        for (int i = start; i > 0; i--) {
            if ((i - matches) > -1) {
                matrix[x][i] = matrix[x][i - matches];
                matrix[x][i - matches] = 0;
            } else {
                matrix[x][i] = 0;
            }
        }
    }
    if (found) {
        return matches;
    } else {
        return 0;
    }
}

int processColBottom(int result, int x, int y, bool clear) {
    int calc = 0;
    y++;
    int start = y;
    int matches = 0;
    bool found = false;
    while (y < 10) {
        int cell = matrix[x][y];
        calc += cell;
        if (result == calc) {
            matches++;
            found = true;
            break;
        }
        if (calc > result) {
            break;
        }
        matches++;
        y++;
    }
    if (clear && found) {
        for (int i = start; i < 10; i++) {
            if ((i + matches) < 10) {
                matrix[x][i] = matrix[x][i + matches];
                matrix[x][i + matches] = 0;
            } else {
                matrix[x][i] = 0;
            }
        }
    }
    if (found) {
        return matches;
    } else {
        return 0;
    }
}

bool processPos(int x, int y, bool clear) {
    int result = matrix[x][y];
    if (result == 0) {
        return false;
    }
    int resRowRight = processRowRight(result, x, y, clear);
    int resColBottom = processColBottom(result, x, y, clear);
    int resRowLeft = processRowLeft(result, x, y, clear);
    int resColTop = processColTop(result, x, y, clear);

    bool match = (resRowLeft > 0 || resColBottom > 0 || resRowRight > 0 || resColTop > 0);
    if (clear && match) {
        matrix[x][y] = 0;
        score += (resRowLeft * 10) + (resColBottom * 10) +  (resRowRight * 10) + (resColTop * 10) ;
    }
    return match;
}

void checkValids() {
    int validMoves = 0;
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (processPos(x, y, false)) {
                validMoves++;
            }
        }
    }
    if (validMoves > 0) {
        printf("You have %d valid moves to make\n", validMoves);
    }
}

int main(int argc, char *argv[])
{
    score = 0;
    calcMatrix();

    int x, y = 0;
    while (x != 99) {
        printMatrix();

        checkValids();

        printf("X:");
        scanf("%d", &x);
        printf("Y:");
        scanf("%d", &y);

        processPos(x, y, true);
    }

    getchar();
}
