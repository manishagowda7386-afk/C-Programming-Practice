#include <stdio.h>
#include <string.h>
#include "../include/account.h"

Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount()
{
    if(totalAccounts >= MAX_ACCOUNTS)
    {
        printf("\nBank Database Full!\n");
        return;
    }

    printf("\n========== CREATE ACCOUNT ==========\n");

    printf("Enter Account Number : ");
    scanf("%d",&accounts[totalAccounts].accountNumber);

    printf("Enter Account Holder Name : ");
    scanf(" %[^\n]",accounts[totalAccounts].accountHolder);

    printf("Enter Initial Balance : ");
    scanf("%f",&accounts[totalAccounts].balance);

    totalAccounts++;

    printf("\n====================================\n");
    printf("Account Created Successfully!\n");
    printf("====================================\n");
}

void displayAllAccounts()
{
    int i;

    if(totalAccounts == 0)
    {
        printf("\nNo Accounts Available!\n");
        return;
    }

    printf("\n========== ALL ACCOUNTS ==========\n");

    for(i=0;i<totalAccounts;i++)
    {
        printf("\nAccount %d\n",i+1);
        printf("------------------------------\n");
        printf("Account Number : %d\n",accounts[i].accountNumber);
        printf("Account Holder : %s\n",accounts[i].accountHolder);
        printf("Balance        : %.2f\n",accounts[i].balance);
    }
}

void searchAccount()
{
    int accountNumber;
    int i;

    if(totalAccounts == 0)
    {
        printf("\nNo Accounts Available!\n");
        return;
    }

    printf("\nEnter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber == accountNumber)
        {
            printf("\n========== ACCOUNT FOUND ==========\n");
            printf("Account Number : %d\n",accounts[i].accountNumber);
            printf("Account Holder : %s\n",accounts[i].accountHolder);
            printf("Balance        : %.2f\n",accounts[i].balance);
            return;
        }
    }

    printf("\nAccount Not Found!\n");
}
