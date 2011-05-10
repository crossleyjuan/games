#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    int nums[10][10];

    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            int val = rand() % 10;
            nums[x][y] = val;
        }
    }

    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            printf("%d ", nums[x][y]);
        }
        printf("\n");
    }

    getchar();
}
