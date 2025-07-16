#include <stdio.h>
#include <string.h>

typedef struct {
    int Empid;
    char empname[50];
    double salary;
} Employee;

void swap(Employee* a, Employee* b) {
    Employee t = *a;
    *a = *b;
    *b = t;
}

int partition(Employee arr[], int low, int high) {
    char* pivot = arr[high].empname;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].empname, pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(Employee arr[], int l, int r, char* name) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        int res = strcmp(name, arr[m].empname);
        if (res == 0)
            return m;
        if (res > 0)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    Employee employees[n];

    for(int i = 0; i < n; i++) {
        printf("Enter details for employee %d\n", i + 1);
        printf("Empid: ");
        scanf("%d", &employees[i].Empid);
        getchar(); // Consume newline character
        printf("Name: ");
        fgets(employees[i].empname, 50, stdin);
        employees[i].empname[strcspn(employees[i].empname, "\n")] = 0; // Remove newline
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }

    quickSort(employees, 0, n - 1);

    char searchName[50];
    printf("Enter the name of the employee to find their salary: ");
    getchar(); // Consume newline character
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    int index = binarySearch(employees, 0, n - 1, searchName);
    if (index != -1) {
        printf("The salary of %s is %.2lf\n", employees[index].empname, employees[index].salary);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}
