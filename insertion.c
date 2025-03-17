#include <stdio.h>

void insertElement(int arr[], int *size, int pos, int val) {
    for (int i = *size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    (*size)++;
}

int main() {
    int arr[100], n, i, pos, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position and value to insert: ");
    scanf("%d %d", &pos, &val);

    insertElement(arr, &n, pos, val);

    printf("Updated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
