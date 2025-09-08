#include <stdio.h>
#include <stdlib.h>

void createArray(int **p, int size) {
    *p = (int *)malloc(sizeof(int) * size);
    if (*p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        (*p)[i] = 0;
    }

    printf("\nArray of size %d is Created...\n", size);
}

void displayArray(int *p, int size) {
    if (p == NULL) {
        printf("\nArray not created yet!\n");
        return;
    }

    printf("\nDisplaying the elements of the Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", p[i]);
    }
    printf("\n");
}

int main() {
    int *p = NULL;
    int size = 0;
    int ch;

    while (1) {
        printf("\nEnter Operation from the following:\n");
        printf("1) Create an Array\n2) Display an Array\n3) Insert in an Array\n4) Delete from an Array\n5) Search in Array\n6) Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the size of the Array: ");
                scanf("%d", &size);
                createArray(&p, size);  // Pass address of pointer
                break;

            case 2:
                displayArray(p, size);
                break;

            case 6:
                printf("\nExiting...\n");
                free(p);  // Free allocated memory
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
