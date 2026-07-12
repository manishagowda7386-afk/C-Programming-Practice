#include <stdio.h>

int main() {
    int n, i;
    float marks, total = 0, average, percentage;
    char grade;

    printf("===== Student Grade Calculator =====\n");

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        printf("Enter marks for Subject %d: ", i);
        scanf("%f", &marks);

        if(marks < 0 || marks > 100) {
            printf("Invalid marks! Please enter marks between 0 and 100.\n");
            return 0;
        }

        total += marks;
    }

    percentage = total / n;
    average = percentage;

    if(percentage >= 90)
        grade = 'A';
    else if(percentage >= 80)
        grade = 'B';
    else if(percentage >= 70)
        grade = 'C';
    else if(percentage >= 60)
        grade = 'D';
    else
        grade = 'F';

    printf("\n----- Result -----\n");
    printf("Total Marks : %.2f\n", total);
    printf("Average     : %.2f\n", average);
    printf("Percentage  : %.2f%%\n", percentage);
    printf("Grade       : %c\n", grade);

    if(grade == 'F')
        printf("Status      : Fail\n");
    else
        printf("Status      : Pass\n");

    return 0;
}
