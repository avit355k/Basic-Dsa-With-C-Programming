#include <stdio.h>
#define MAX_Rows 100
#define MAX_Colm 100

int main()
{
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
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colm; j++)
        {
            printf("Matrix[%d][%d]:", i, j);
            scanf("%d", &Matrix[i][j]);
        }
    }

    printf("The Original Matrix Is :\n");
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colm; j++)
        {
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }

    // Count the number of zero elements
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colm; j++)
        {
            if (Matrix[i][j] == 0)
            {
                Sparse++;
            }
        }
    }
    int Transpose[Colm][Rows];
    if (Sparse > Check)
    {
        printf("It's a Sparse Matrix with %d number of zero elements!\n", Sparse);

        printf("The Transpose Of The Matrix Is :\n");
        for (int i = 0; i < Colm; i++)
        {
            for (int j = 0; j < Rows; j++)
            {
                Transpose[i][j]=Matrix[j][i];
                printf("%d\t", Transpose[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("It's a Dense Matrix with %d number of zero Elements!\n", Sparse);
    }
    return 0;
}
