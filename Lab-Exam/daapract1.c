#include <stdio.h>
#include<stdlib.h>
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int mergedArray[], int *mergeComparisons) {
    int i = 0, j = 0, k = 0;
    *mergeComparisons = 0;

    while (i < size1 && j < size2) {
        (*mergeComparisons)++;
        if (arr1[i] < arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            mergedArray[k++] = arr2[j++];
        } else {
            mergedArray[k++] = arr1[i++];
            mergedArray[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }

    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }
}

int binarySearch(int arr[], int size, int key, int *searchComparisons) {
    int l = 0, r= size - 1,m;
    *searchComparisons = 0;

    while (l <= r) {
        m = l+ (r - l) / 2;
        (*searchComparisons)++;
        if (arr[m] == key) {
            return m;
        } else if (arr[m] < key) {
            l= m+ 1;
        } else {
            r = m- 1;
        }
    }
    return -1;
}
int main() {
    int i,j,size1,size2,key,sc=0;
    int arr1[20],arr2[20],mergedArray[40];
    int mergeComparisons = 0,index;
    printf("enter number of elements in array1\n");
    scanf("%d",&size1);
    printf("enter number of elements in array2\n");
    scanf("%d",&size2);
    printf("enter the elements of array 1\n");
    for(i=0;i<size1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("enter the elements of array 2\n");
    for(i=0;i<size2;i++){
        scanf("%d",&arr2[i]);
    }
    printf("enter search key element\n");
    scanf("%d",&key);

    mergeArrays(arr1, size1, arr2, size2, mergedArray, &mergeComparisons);

    printf("Merged Array: ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\nMerge Comparisons: %d\n", mergeComparisons);
    index = binarySearch(mergedArray, size1 + size2, key, &sc);

    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }
    printf("Search Comparisons: %d\n", sc);

    return 0;
}