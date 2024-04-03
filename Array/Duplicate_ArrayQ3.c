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
    
    printf("The Original Array:");
    for (int i = 0; i < n; i++) {
        printf("%d\t", Arr[i]);
    }
    
    // Remove the duplicate elements
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Arr[i] == Arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    Arr[k] = Arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    printf("\nThe Array After Removing Duplicate Elements:");
    for (int i = 0; i < n; i++) {
        printf("%d\t", Arr[i]);
    }

    return 0;
}
