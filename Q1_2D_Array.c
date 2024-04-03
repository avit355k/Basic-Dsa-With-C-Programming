#include <stdio.h>
int main()
{
    int Rows, Colm;
    printf("Enter The Number Of Rows:");
    scanf("%d", &Rows);
    printf("Enter The Number Of Column:");
    scanf("%d", &Colm);

    int Matrix[Rows][Colm];
    printf("Enter The Value OF The Matrix:\n");
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colm; j++)
        {
            printf("Matrix[%d][%d]:", i, j);
            scanf("%d", &Matrix[i][j]);
        }
    }

    printf("THe Original Matrix Is:\n");
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colm; j++)
        {
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }

    printf("The Matrix  in Row-Major Order:\n");
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colm; j++)
        {
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }

    // Display the array in column-major order
    printf("The Matrix in Column-Major Order:\n");
    for (int j = 0; j < Colm; j++)
    {
        for (int i = 0; i < Rows; i++)
        {
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}