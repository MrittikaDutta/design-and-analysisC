#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    double marks;
} Student;

void merge(Student arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    Student L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].marks <= R[j].marks) {
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

int linearSearch(Student arr[], int n, char* name) {
    for (int i = 0; i < n; i++)
        if (strcmp(arr[i].name, name) == 0)
            return i;
    return -1;
}

int main() {
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student* students = (Student*)malloc(n * sizeof(Student));

    for (i = 0; i < n; i++) {
        printf("Enter ID, name, and marks for student %d: ", i + 1);
        scanf("%d %s %lf", &students[i].id, students[i].name, &students[i].marks);
    }

    mergeSort(students, 0, n - 1);

    char searchName[50];
    printf("Enter the name of the student to find their marks: ");
    scanf("%s", searchName);

    int index = linearSearch(students, n, searchName);
    if (index != -1) {
        printf("The marks of %s are %.2f\n", students[index].name, students[index].marks);
    } else {
        printf("Student not found.\n");
    }

    free(students);
    return 0;
}0