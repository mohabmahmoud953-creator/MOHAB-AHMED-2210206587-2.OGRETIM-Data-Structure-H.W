#include <stdio.h>

void convertToSparse(int matrix[4][4], int row, int col) {
    int sparse[10][3]; 
    int k = 1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = k - 1;

    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int matrix[4][4] = {
        {0, 0, 3, 0},
        {0, 0, 0, 0},
        {0, 5, 0, 0},
        {0, 0, 0, 0}
    };

    convertToSparse(matrix, 4, 4);
    return 0;
}
