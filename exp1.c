//Experiment 1:
// Implement the merge algorithm between two sorted array by considering the following:
// 1. Same data may be present in both the array.
// 2. if data present in both array and resulting sorted array does not contain data that is present
// both the array.
// 3. Then Apply binary search on the sorted array obtain merging two sorted array to find an
// element. Also find number of comparison required to get that search key element.
// Example: array 1: 10, 30, 40, 50
// Array2: 20, 30, 70, 80
// Result: 10, 20, 40, 50, 70, 80
#include <stdio.h>
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            result[k++] = arr2[j++];
        } else {
            i++;
            j++;
        }
    }
    while (i < n1) {
        result[k++] = arr1[i++];
    }
    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int binarySearch(int arr[], int l, int r, int x, int *comparisons) {
    while (l <= r) {
        (*comparisons)++;
        int m = l + (r - l) / 2;
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
    mergeArrays(arr1, n1, arr2, n2, result);
    int n3 = n1 + n2; 
    printf("Merged Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    int x;
    printf("Enter search key: ");
    scanf("%d", &x);
    int comparisons = 0;
    int index = binarySearch(result, 0, n3-1, x, &comparisons);
    if (index != -1) {
        printf("Element %d found at index %d with %d comparisons.\n", x, index, comparisons);
    } else {
        printf("Element %d not found. Number of comparisons made: %d.\n", x, comparisons);
    }
    return 0;
}
