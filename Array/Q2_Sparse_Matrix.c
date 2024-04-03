#include <stdio.h>
#define MAX_Rows 100
#define MAX_Colm 100

int main() {
    int Rows, Colm;
    printf("Enter The Number Of Rows:");
    scanf("%d", &Rows);
    printf("Enter The Number Of Columns:");
    scanf("%d", &Colm);

    int Matrix[Rows][Colm];
    int Sparse = 0;
    int Element = Rows * Colm;
    int Check = Element / 2;

    printf("Enter The Value Of The Matrix:\n");
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Colm; j++) {
            printf("Matrix[%d][%d]:", i, j);
            scanf("%d", &Matrix[i][j]);
        }
    }

    printf("The Original Matrix Is :\n");
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Colm; j++) {
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }

    // Count the number of zero elements
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Colm; j++) {
            if (Matrix[i][j] == 0) {
                Sparse++;
            }
        }
    }

    if (Sparse > Check) {
        printf("It's a Sparse Matrix with %d number of zero elements!\n", Sparse);
    } else if (Sparse <= Check) {
        printf("It's a Dense Matrix with %d number of non-zero Elements!\n", Element - Sparse);
    }

    printf("Matrix in Tuple Format (Row, Column, Value):\n");
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Colm; j++) {
            if (Matrix[i][j] != 0) {
                printf("%d\t%d\t%d\n", i, j, Matrix[i][j]);
            }
        }
    }

    return 0;
}
