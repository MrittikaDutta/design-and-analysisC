#include <stdio.h>
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[], int* n3) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            result[k++] = arr2[j++];
        } else {
            result[k++] = arr1[i++];
            j++;
        }
    }
    while (i < n1) {
        result[k++] = arr1[i++];
    }
    while (j < n2) {
        result[k++] = arr2[j++];
    }
    *n3 = k;
}
int binarySearch(int arr[], int l, int r, int x, int *comparisons) {
    while (l <= r) {
        (*comparisons)++;
        int m = l + (r - l) / 2;
        if (arr[m] == x) {
            return m;
        }
        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int n1, n2;
    printf("Enter number of elements in array 1: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements of array 1: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in array 2: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements of array 2: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int result[n1 + n2];
    int n3; 
    mergeArrays(arr1, n1, arr2, n2, result, &n3);

    printf("Merged Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    int x;
    printf("Enter search key: ");
    scanf("%d", &x);

    int comparisons = 0;
    int index = binarySearch(result, 0, n3 - 1, x, &comparisons);
    if (index != -1) {
        printf("Element %d found at index %d with %d comparisons.\n", x, index, comparisons);
    } else {
        printf("Element %d not found. Number of comparisons made: %d.\n", x, comparisons);
    }

    return 0;
}
