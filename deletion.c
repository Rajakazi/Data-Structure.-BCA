#include <stdio.h>

void deleteElement(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    (*size)--;
}

int main() {
    int arr[100], n, i, pos;

    // Step 1: Take input for array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Step 2: Input array elements
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Step 3: Take input for position to delete
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // Step 4: Delete element
    deleteElement(arr, &n, pos);

    // Step 5: Display updated array
    printf("Updated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
