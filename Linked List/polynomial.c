#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial in sorted order of exponents
void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL || exponent > (*poly)->exponent) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        struct Term* temp = *poly;
        while (temp->next != NULL && temp->next->exponent > exponent) {
            temp = temp->next;
        }
        newTerm->next = temp->next;
        temp->next = newTerm;
    }
}

// Function to display a polynomial
void displayPoly(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
            printf("+ ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Copy remaining terms from poly1
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    // Copy remaining terms from poly2
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

// Function to subtract two polynomials
struct Term* subtractPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, -poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coefficient - poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Copy remaining terms from poly1
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    // Copy remaining terms from poly2 with negative coefficients
    while (poly2 != NULL) {
        insertTerm(&result, -poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

// Function to free memory allocated for the polynomial
void freePoly(struct Term* poly) {
    struct Term* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    int n, coeff, exp;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent for each term in the first polynomial:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent for each term in the second polynomial:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Display the input polynomials
    printf("First polynomial: ");
    displayPoly(poly1);
    printf("Second polynomial: ");
    displayPoly(poly2);

    // Perform addition and subtraction
    struct Term* sum = addPolynomials(poly1, poly2);
    struct Term* difference = subtractPolynomials(poly1, poly2);

    // Display the results
    printf("Sum of the polynomials: ");
    displayPoly(sum);
    printf("Difference of the polynomials: ");
    displayPoly(difference);

    // Free memory
    freePoly(poly1);
    freePoly(poly2);
    freePoly(sum);
    freePoly(difference);

    return 0;
}
