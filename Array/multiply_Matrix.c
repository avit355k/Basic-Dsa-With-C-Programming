#include <stdio.h>

int main() {
    int m, n, p, q;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication is not possible. The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }
    int Matrix1[m][n], Matrix2[p][q], Result[m][q];

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Matrix1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &Matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            Result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                Result[i][j] += Matrix1[i][k] * Matrix2[k][j]; // Multiply, not add
            }
        }
    }

    printf("The resultant matrix after multiplying:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d\t", Result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
