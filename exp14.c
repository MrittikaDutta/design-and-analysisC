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
        if (arr[j] > pivot) {
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

int linearSearch(int arr[], int n, int x, int* c) {
    for(int i = 0; i < n; i++) {
        (*c)++;
        if(arr[i] == x)
            return i;
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
    int result = linearSearch(arr, n, x, &c);
    if(result != -1)
        printf("Element found at index %d. Number of comparisons made: %d\n", result, c);
    else
        printf("Element not found. Number of comparisons made: %d\n", c);
    free(arr);
    return 0;
}
