#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void *a, void *b, size_t size) {

    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void heapify(void *arr, int n, int i, size_t size,
             int (*compare)(const void *, const void *)) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    void *base = arr;

    if (left < n &&
        compare((char *)base + left * size,
                (char *)base + largest * size) > 0)
        largest = left;

    if (right < n &&
        compare((char *)base + right * size,
                (char *)base + largest * size) > 0)
        largest = right;

    if (largest != i) {

        swap((char *)base + i * size,
             (char *)base + largest * size,
             size);

        heapify(arr, n, largest, size, compare);
    }
}

void heapSort(void *arr, int n, size_t size,
              int (*compare)(const void *, const void *)) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, size, compare);

    for (int i = n - 1; i > 0; i--) {

        swap((char *)arr,
             (char *)arr + i * size,
             size);

        heapify(arr, i, 0, size, compare);
    }
}

int compareInt(const void *a, const void *b) {

    int x = *(int *)a;
    int y = *(int *)b;

    if (x > y)
        return 1;

    if (x < y)
        return -1;

    return 0;
}

int main() {

    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n, sizeof(int), compareInt);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}