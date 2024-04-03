#include <stdio.h>
int main()
{
    int n;
    printf("Enter The Size Of the Array:");
    scanf("%d", &n);
    int Arr[n];
    printf("Enter The Elements OF The Array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }
    printf("The Original Array Is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", Arr[i]);
    }
    printf("\n");
    // Condition For Largest And Smallest element.
    int Largest = Arr[0];
    int Smallest = Arr[0];

    for (int i = 1; i < n; i++)
    {
        if (Arr[i] > Largest)
        {
            Largest = Arr[i];
        }
        // check if The Elments Is smallest from Smallest!
        if (Arr[i] < Smallest)
        {
            Smallest = Arr[i];
        }
    }

    printf("The Largest Element Of The Array Is: %d\n", Largest);
    printf("The Smallest Element Of The Array Is : %d\n", Smallest);
    return 0;
}