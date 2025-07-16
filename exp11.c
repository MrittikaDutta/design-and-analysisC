#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int binarySearch(int arr[], int l, int r, int x, int* c) {
    int index = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        (*c)++;
        if (arr[m] == x) {
            index = m;
            r = m - 1;
        } else if (arr[m] < x) 
            r = m - 1;
        else
            l = m + 1;
    }
    return index;
}

int main() {
    int n, x, c = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n-1);
    scanf("%d", &x);
    int firstIndex = binarySearch(arr, 0, n-1, x, &c);
    if(firstIndex != -1) {
        printf("Element found at index %d", firstIndex);
        for(int i = firstIndex + 1; i < n && arr[i] == x; i++) {
            printf(", %d", i);
        }
    } else {
        printf("Element not found.");
    }
    printf(" Number of comparisons made: %d\n", c);
    free(arr);
    return 0;
}
