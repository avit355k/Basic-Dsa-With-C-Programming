#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int Arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    printf("The original array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", Arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        // Sorting the array in ascending order
        int temp;
        for (int j = i + 1; j < n; j++) {
            if (Arr[i] > Arr[j]) {
                temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }

    printf("The second smallest element is: %d\n", Arr[1]);
    printf("The second largest element is: %d\n", Arr[n - 2]);

    return 0;
}
