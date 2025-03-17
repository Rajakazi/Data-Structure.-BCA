//write a program to define the DMA all format in c programming 
#include <stdio.h>
#include <stdlib.h>  

int main() {
    int *ptr1, *ptr2, *ptr3;
    int n, i;

    // 1️⃣ malloc(): Allocate memory for 'n' integers
    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr1 = (int *)malloc(n * sizeof(int)); // Allocate memory
    if (ptr1 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nMemory allocated using malloc(). Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr1[i]);
    }

    printf("Elements in malloc(): ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // 2️⃣ calloc(): Allocate memory for 'n' integers, initialized to zero
    ptr2 = (int *)calloc(n, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nMemory allocated using calloc(): ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr2[i]);  // Default values will be zero
    }
    printf("\n");

    // 3️⃣ realloc(): Resize memory allocated by malloc()
    int newSize;
    printf("\nEnter new size for realloc(): ");
    scanf("%d", &newSize);

    ptr3 = (int *)realloc(ptr1, newSize * sizeof(int));
    if (ptr3 == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    } else {
        ptr1 = ptr3;  // Point ptr1 to newly allocated memory
    }

    printf("\nMemory resized using realloc(). Enter %d elements:\n", newSize);
    for (i = 0; i < newSize; i++) {
        scanf("%d", &ptr1[i]);
    }

    printf("Elements in realloc(): ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // 4️⃣ free(): Deallocate memory
    free(ptr1);
    free(ptr2);

    printf("\nMemory deallocated successfully.\n");

    return 0;
}
