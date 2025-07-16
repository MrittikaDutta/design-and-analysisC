#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    double marks;
} Student;

void merge(Student arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    Student L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].name, R[j].name) <= 0) {
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

void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int binarySearch(Student arr[], int n, char* name) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;

        int res = strcmp(name, arr[middle].name);
        if (res == 0)
            return middle;
        if (res > 0)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); // consume newline

    Student* students = (Student*)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        getchar(); // consume newline
        printf("Enter name for student %d: ", i + 1);
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline character
        printf("Enter marks for student %d: ", i + 1);
        scanf("%lf", &students[i].marks);
        getchar(); // consume newline
    }

    mergeSort(students, 0, n - 1);

    char searchName[50];
    printf("Enter the name of the student to find their marks: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    int index = binarySearch(students, n, searchName);
    if (index != -1) {
        printf("The marks of %s are %.2f\n", students[index].name, students[index].marks);
    } else {
        printf("Student not found.\n");
    }

    free(students);
    return 0;
}
