#include <stdio.h>
#include <string.h>
#include "../include/account.h"

Account accounts[MAX_ACCOUNTS];
int totalAccounts=0;

void createAccount()
{
    if(totalAccounts>=MAX_ACCOUNTS)
    {
        printf("\nDatabase Full!\n");
        return;
    }

    printf("\nEnter Account Number : ");
    scanf("%d",&accounts[totalAccounts].accountNumber);

    printf("Enter Account Holder : ");
    scanf(" %[^\n]",accounts[totalAccounts].accountHolder);

    printf("Enter Initial Balance : ");
    scanf("%f",&accounts[totalAccounts].balance);

    totalAccounts++;

    printf("\nAccount Created Successfully.\n");
}

void displayAllAccounts()
{
    int i;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Found.\n");
        return;
    }

    printf("\n=========== ACCOUNT LIST ===========\n");

    for(i=0;i<totalAccounts;i++)
    {
        printf("\nAccount %d\n",i+1);
        printf("Number : %d\n",accounts[i].accountNumber);
        printf("Name   : %s\n",accounts[i].accountHolder);
        printf("Balance: %.2f\n",accounts[i].balance);
    }
}

void searchAccount()
{
    int number,i;

    printf("\nEnter Account Number : ");
    scanf("%d",&number);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==number)
        {
            printf("\nAccount Found\n");
            printf("Name : %s\n",accounts[i].accountHolder);
            printf("Balance : %.2f\n",accounts[i].balance);
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}
