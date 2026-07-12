/*
 * Project: Student Record Management System
 * Language: C
 * Description:
 * Demonstrates the use of structures by storing
 * and displaying student records.
 *
 * Author: Manisha TM
 */

#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {

    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(i = 0; i < n; i++) {

        printf("\nStudent %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for(i = 0; i < n; i++) {

        printf("\nID    : %d", s[i].id);
        printf("\nName  : %s", s[i].name);
        printf("\nMarks : %.2f\n", s[i].marks);
    }

    return 0;
}
