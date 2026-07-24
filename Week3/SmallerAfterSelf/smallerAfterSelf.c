#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int value;
    int index;
};

void merge(struct Node arr[], int low, int mid, int high, int ans[]) {

    struct Node temp[high - low + 1];

    int left = low;
    int right = mid + 1;
    int k = 0;

    printf("\n=====================================================\n");
    printf("Merging Subarrays\n");

    printf("Left  [%d..%d] : ", low, mid);
    for (int i = low; i <= mid; i++) {
        printf("%d ", arr[i].value);
    }

    printf("\nRight [%d..%d] : ", mid + 1, high);
    for (int i = mid + 1; i <= high; i++) {
        printf("%d ", arr[i].value);
    }
    printf("\n=====================================================\n");

    while (left <= mid && right <= high) {

        printf("\nComparing %d and %d\n",
               arr[left].value,
               arr[right].value);

        if (arr[left].value <= arr[right].value) {

            printf("%d <= %d\n",
                   arr[left].value,
                   arr[right].value);

            printf("Smaller elements already taken from Right : ");

            if (right == mid + 1) {
                printf("None");
            } else {
                for (int i = mid + 1; i < right; i++) {
                    printf("%d ", arr[i].value);
                }
            }

            printf("\nCount Added = %d\n",
                   right - (mid + 1));

            ans[arr[left].index] += right - (mid + 1);

            temp[k++] = arr[left++];

        } else {

            printf("%d < %d\n",
                   arr[right].value,
                   arr[left].value);

            printf("Move %d from Right Array\n",
                   arr[right].value);

            temp[k++] = arr[right++];
        }
    }

    while (left <= mid) {

        printf("\nRemaining Left Element : %d\n",
               arr[left].value);

        printf("Smaller elements already taken from Right : ");

        if (right == mid + 1) {
            printf("None");
        } else {
            for (int i = mid + 1; i < right; i++) {
                printf("%d ", arr[i].value);
            }
        }

        printf("\nCount Added = %d\n",
               right - (mid + 1));

        ans[arr[left].index] += right - (mid + 1);

        temp[k++] = arr[left++];
    }

    while (right <= high) {

        printf("\nRemaining Right Element : %d\n",
               arr[right].value);

        temp[k++] = arr[right++];
    }

    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }

    printf("\nMerged Array : ");

    for (int i = low; i <= high; i++) {
        printf("%d ", arr[i].value);
    }

    printf("\n");
    printf("=====================================================\n");
}

void mergeSort(struct Node arr[], int low, int high, int ans[]) {

    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid, ans);
    mergeSort(arr, mid + 1, high, ans);

    merge(arr, low, mid, high, ans);
}

int main() {

    int n;

    printf("Enter size of Array: ");
    scanf("%d", &n);

    struct Node arr[n];
    int ans[n];

    printf("Enter values of the Array:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        ans[i] = 0;
    }

    mergeSort(arr, 0, n - 1, ans);

    printf("\n=========================================\n");
    printf("Final Counts\n");
    printf("=========================================\n");

    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i].value, ans[arr[i].index]);
    }

    printf("\nAnswer Array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}