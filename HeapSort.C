// Heap Sort in C
#include <stdio.h>
int count = 0;
void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
    count++;
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    printf("\nParent: %d", arr[largest]);
    printf("\nChildren: %d %d ", arr[left], arr[right]);
    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray2(int arr[], int N)
{
    for (int i = N - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[15];
    int N, i, opt;
    printf("Enter number of elementsW of array:");
    scanf("%d", &N);
    printf("Enter element of array:");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n\t-----The Parent and Child pairs are-----");
    heapSort(arr, N);
    printf("\n%d", count);
    printf("\n\t-----Sorted array is-----\n");
    printArray2(arr, N);
    return 0;
}