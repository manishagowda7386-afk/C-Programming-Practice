/*
-------------------------------------------------------
Project : Banking Management System
Language: C

Author  : Manisha TM

Description:
A console-based Banking Management System.

Version : 1.1
-------------------------------------------------------
*/

#include <stdio.h>

struct Account
{
    int accountNumber;
    char accountHolder[50];
    float balance;
};

struct Account account;
int accountCreated = 0;

void displayMenu();
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();

int main()
{
    int choice;

    while (1)
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                printf("\nThank you for using Banking Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu()
{
    printf("\n========================================\n");
    printf("      BANKING MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

void createAccount()
{
    printf("\n========== CREATE ACCOUNT ==========\n");

    printf("Enter Account Number : ");
    scanf("%d", &account.accountNumber);

    printf("Enter Account Holder Name : ");
    scanf(" %49[^\n]", account.accountHolder);

    printf("Enter Initial Balance : ");
    scanf("%f", &account.balance);

    if(account.balance < 0)
        account.balance = 0;

    accountCreated = 1;

    printf("\nAccount created successfully!\n");
}

void depositMoney()
{
    float amount;

    if(accountCreated == 0)
    {
        printf("\nPlease create an account first!\n");
        return;
    }

    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    account.balance += amount;

    printf("Deposit Successful!\n");
    printf("Current Balance: %.2f\n", account.balance);
}

void withdrawMoney()
{
    float amount;

    if(accountCreated == 0)
    {
        printf("\nPlease create an account first!\n");
        return;
    }

    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    if(amount > account.balance)
    {
        printf("Insufficient Balance!\n");
        return;
    }

    account.balance -= amount;

    printf("Withdrawal Successful!\n");
    printf("Current Balance: %.2f\n", account.balance);
}

void checkBalance()
{
    if(accountCreated == 0)
    {
        printf("\nPlease create an account first!\n");
        return;
    }

    printf("\n========== ACCOUNT DETAILS ==========\n");
    printf("Account Number : %d\n", account.accountNumber);
    printf("Account Holder : %s\n", account.accountHolder);
    printf("Balance        : %.2f\n", account.balance);
}
