#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
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

int removeDuplicates(int arr[], int n){
    if(n==0 || n==1)
        return n;
    int temp[n];
    int j = 0;
    for(int i=0; i<n-1; i++)
        if(arr[i] != arr[i+1])
            temp[j++] = arr[i];
    temp[j++] = arr[n-1];
    for(int i=0; i<j; i++)
        arr[i] = temp[i];
    return j;
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
    mergeSort(arr, 0, n-1);
    n = removeDuplicates(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    scanf("%d", &x);
    int result = linearSearch(arr, n, x, &c);
    if(result != -1)
        printf("Element found at index %d. Number of comparisons made: %d\n", result, c);
    else
        printf("Element not found. Number of comparisons made: %d\n", c);
    free(arr);
    return 0;
}
