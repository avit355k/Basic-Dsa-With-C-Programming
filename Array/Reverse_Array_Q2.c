#include <stdio.h>
int main()
{
    int n;
    printf("Enter The Size OF The Array:");
    scanf("%d", &n);
    int Arr[n];

    printf("Enter The Elements Of The Array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }
    printf("The Original Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", Arr[i]);
    }
    // Reverse The Array!
    int Start = 0;
    int End = n - 1;
    while (Start < End)
    {
        // swapping the fisrt position with last position!
        int temp = Arr[Start];
        Arr[Start] = Arr[End];
        Arr[End] = temp;
        Start++;
        End--;
    }

    printf("\nThe Reverse Array Is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", Arr[i]);
    }

    return 0;
}