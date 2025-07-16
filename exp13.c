#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int arr[], int l, int r, int x, int* c) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        (*c)++;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n, x, c = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n-1);
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n-1, x, &c);
    if(result != -1)
        printf("Element found at index %d Number of comparisons made: %d\n", result, c);
    else
        printf("Element not found Number of comparisons made: %d\n", c);
    free(arr);
    return 0;
}
