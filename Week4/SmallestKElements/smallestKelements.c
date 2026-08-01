#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {

    int randomIndex = low + rand() % (high - low + 1);

    swap(&arr[randomIndex], &arr[high]);

    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

// QuickSelect
void quickSelect(int arr[], int low, int high, int k) {

    if (low >= high)
        return;

    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k)
        return;

    else if (pivotIndex > k)
        quickSelect(arr, low, pivotIndex - 1, k);

    else
        quickSelect(arr, pivotIndex + 1, high, k);

    }


void generateArray(int arr[], int n) {

    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

int main() {

    srand(time(NULL));

    FILE *fp = fopen("runtime.csv", "w");

    if (fp == NULL) {
        printf("Error creating runtime.csv\n");
        return 1;
    }

    fprintf(fp, "DatasetSize,Runtime_ms\n");

    int sizes[] = {
        100000,
        200000,
        400000,
        800000,
        1600000,
        3200000
    };

    int totalSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("=============================================\n");
    printf(" QuickSelect Average Runtime Benchmark\n");
    printf("=============================================\n");
    printf("%-15s %-15s\n", "Dataset Size", "Runtime (ms)");

    for (int i = 0; i < totalSizes; i++) {

        int n = sizes[i];
        int k = n / 10;

        double totalRuntime = 0.0;

        for (int run = 0; run < 20; run++) {

            int *arr = (int *)malloc(n * sizeof(int));

            if (arr == NULL) {
                printf("Memory allocation failed.\n");
                fclose(fp);
                return 1;
            }

            generateArray(arr, n);

            clock_t start = clock();

            quickSelect(arr, 0, n - 1, k - 1);

            clock_t end = clock();

            totalRuntime +=
                ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

            free(arr);
        }

        double averageRuntime = totalRuntime / 20.0;

        printf("%-15d %-15.3f\n", n, averageRuntime);

        fprintf(fp, "%d,%.3f\n", n, averageRuntime);
    }

    fclose(fp);

    printf("\nRuntime data saved to runtime.csv\n");

}