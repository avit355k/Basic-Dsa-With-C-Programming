#include <stdio.h>

int linearSearch(int Arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (Arr[i] == key) {
            return i; // Return the index where the key was found
        }
    }
    return -1; // Return -1 if the key is not found
}

int binarySearch(int Arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (Arr[mid] == key) {
            return mid; // Return the index where the key was found
        }

        if (Arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int n, choice, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int Arr[n];
    printf("Enter the elements of the array in Sortedwise:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    printf("The original array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", Arr[i]);
    }

    do {
        printf("\nChoose an option:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                int linearIndex = linearSearch(Arr, n, key);
                if (linearIndex != -1) {
                    printf("Element found at index %d\n", linearIndex);
                } else {
                    printf("Element not found in the array\n");
                }
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                int binaryIndex = binarySearch(Arr, 0, n - 1, key);
                if (binaryIndex != -1) {
                    printf("Element found at index %d\n", binaryIndex);
                } else {
                    printf("Element not found in the array\n");
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
