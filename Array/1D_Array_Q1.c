#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int n, Element;
    int Arr[MAX_SIZE];

    printf("Enter the No. Of Element of The Array (max %d):", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("INVALID NO OF INPUT OF ELEMENT\n");
        return 1;
    }

    printf("Enter %d Elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    printf("The Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", Arr[i]);
    }
    printf("\n");

    int position;
    printf("Enter The Position where the element should be inserted (1 to %d):", n + 1);
    scanf("%d", &position);

    if (position > n + 1 || position < 1) {
        printf("Invalid Position! Please check again!\n");
        return 1;
    }

    printf("Enter The Value Of The element to be Inserted:");
    scanf("%d", &Element);

    for (int i = n; i >= position; i--) {
        Arr[i] = Arr[i - 1];
    }
    Arr[position - 1] = Element;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", Arr[i]);
    }

    printf("\nEnter The Position from where the element should be deleted (1 to %d):", n);
    scanf("%d", &position);

    if (position > n || position < 1) {
        printf("Invalid Position! Please check again!\n");
        return 1;
    }

    for (int i = position - 1; i < n - 1; i++) {
        Arr[i] = Arr[i + 1];
    }
    n--;

    printf("Array after Deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", Arr[i]);
    }

    return 0;
}
