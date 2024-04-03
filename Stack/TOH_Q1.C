#include <stdio.h>

// Function to move disks from source to destination using auxiliary rod
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        // Base case: Move the top disk from source to destination
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary rod using destination as auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary rod to destination using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int numDisks;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Ensure a positive number of disks is entered
    if (numDisks < 1) {
        printf("Please enter a positive integer for the number of disks.\n");
        return 1; // Exit with an error code
    }

    // Function call to solve Tower of Hanoi problem
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0; // Exit successfully
}
