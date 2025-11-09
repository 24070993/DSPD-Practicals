#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int age;
    float avgMarks;
};

void bubbleSort(struct Student arr[], int n) {
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].avgMarks < arr[j + 1].avgMarks) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Average Marks: ");
        scanf("%f", &students[i].avgMarks);
    }

    // Sort students by avgMarks
    bubbleSort(students, n);

    // Print sorted list
    printf("\nStudents sorted by Average Marks (Descending Order):\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s | Roll: %d | Age: %d | Avg Marks: %.2f\n",
               students[i].name, students[i].roll, students[i].age, students[i].avgMarks);
            }

return 0;
}
