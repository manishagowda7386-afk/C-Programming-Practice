#include <stdio.h>

int main() {
    int empId;
    char name[50];
    float basicSalary, hra, da, tax, grossSalary, netSalary;

    printf("========== Employee Salary Calculator ==========\n");

    printf("Enter Employee ID: ");
    scanf("%d", &empId);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary);

    hra = basicSalary * 0.20;
    da = basicSalary * 0.15;
    tax = basicSalary * 0.10;

    grossSalary = basicSalary + hra + da;
    netSalary = grossSalary - tax;

    printf("\n========== Salary Slip ==========\n");
    printf("Employee ID   : %d\n", empId);
    printf("Employee Name : %s\n", name);
    printf("Basic Salary  : %.2f\n", basicSalary);
    printf("HRA (20%%)     : %.2f\n", hra);
    printf("DA (15%%)      : %.2f\n", da);
    printf("Tax (10%%)     : %.2f\n", tax);
    printf("Gross Salary  : %.2f\n", grossSalary);
    printf("Net Salary    : %.2f\n", netSalary);

    return 0;
}
