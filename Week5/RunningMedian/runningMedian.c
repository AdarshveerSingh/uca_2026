#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void maxHeapify(int heap[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        maxHeapify(heap, n, largest);
    }
}

void maxInsert(int **heap, int *n, int value)
{
    int *temp = realloc(*heap, (*n + 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    *heap = temp;

    (*heap)[*n] = value;
    (*n)++;

    int index = *n - 1;

    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if ((*heap)[index] <= (*heap)[parent])
            break;

        int swap = (*heap)[index];
        (*heap)[index] = (*heap)[parent];
        (*heap)[parent] = swap;

        index = parent;
    }
}

int extractMax(int **heap, int *n)
{
    int value = (*heap)[0];

    (*heap)[0] = (*heap)[*n - 1];
    (*n)--;

    if (*n > 0)
        maxHeapify(*heap, *n, 0);

    return value;
}

void minHeapify(int heap[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        minHeapify(heap, n, smallest);
    }
}

void minInsert(int **heap, int *n, int value)
{
    int *temp = realloc(*heap, (*n + 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    *heap = temp;

    (*heap)[*n] = value;
    (*n)++;

    int index = *n - 1;

    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if ((*heap)[index] >= (*heap)[parent])
            break;

        int swap = (*heap)[index];
        (*heap)[index] = (*heap)[parent];
        (*heap)[parent] = swap;

        index = parent;
    }
}

int extractMin(int **heap, int *n)
{
    int value = (*heap)[0];

    (*heap)[0] = (*heap)[*n - 1];
    (*n)--;

    if (*n > 0)
        minHeapify(*heap, *n, 0);

    return value;
}

void insert(int **maxHeap, int *maxSize,
            int **minHeap, int *minSize,
            int num)
{

    if (*maxSize == 0 || num <= (*maxHeap)[0])
    {
        maxInsert(maxHeap, maxSize, num);
    }
    else
    {
        minInsert(minHeap, minSize, num);
    }

    if (*maxSize > *minSize + 1)
    {
        int value = extractMax(maxHeap, maxSize);
        minInsert(minHeap, minSize, value);
    }
    else if (*minSize > *maxSize + 1)
    {
        int value = extractMin(minHeap, minSize);
        maxInsert(maxHeap, maxSize, value);
    }
}

float getMedian(int maxHeap[], int maxSize,
                int minHeap[], int minSize)
{
    if (maxSize == 0 && minSize == 0)
    {
        return 0.0f;
    }

    if (maxSize == minSize)
    {
        return (maxHeap[0] + minHeap[0]) / 2.0f;
    }

    if (maxSize > minSize)
    {
        return (float)maxHeap[0];
    }

    return (float)minHeap[0];
}

int main()
{
    int *maxHeap = NULL;
    int *minHeap = NULL;

    int maxSize = 0;
    int minSize = 0;

    int n;

    printf("How many numbers? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int num;

        printf("Enter number: ");
        scanf("%d", &num);

        insert(&maxHeap, &maxSize,
               &minHeap, &minSize,
               num);

        printf("Median: %.2f\n",
               getMedian(maxHeap, maxSize,
                         minHeap, minSize));
    }

    free(maxHeap);
    free(minHeap);
}